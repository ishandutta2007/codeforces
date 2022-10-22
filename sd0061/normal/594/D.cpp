#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
typedef long long LL;
using namespace std;
const int N = 200005;
const int M = 1000005;
const int Q = 1e9 + 7;
int n , m , w;
int a[N] , s[N]; 
bool f[M];
int p[M] , t , L[M];
int c[N] , res[N];
struct query {
    int l , r , id;
    bool operator < (const query &R) const {
        if (l != R.l)
            return l < R.l;
        return r < R.r;
    }
}q[N];
int inv(int x){
    return x == 1 ? 1 : (LL)(Q - Q / x) * inv(Q % x) % Q;
}

int main() {
    scanf("%d" , &n);
    s[0] = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        w = max(w , a[i]);
        s[i] = (LL)s[i - 1] * a[i] % Q;
    }
    for (int i = 2 ; i * i <= w ; ++ i) {
        if (f[i]) continue;
        p[t ++] = i;
        for (int j = i * i ; j <= w ; j += i)
            f[j] = 1; 
    }
    vector<query> opt;
    for (int i = 1 ; i <= n ; ++ i) {
        int x = a[i];
        for (int j = 0 ; j < t && p[j] * p[j] <= x ; ++ j) {
            if (x % p[j] == 0) {
                opt.push_back((query){L[p[j]] , (LL)(p[j] - 1) * inv(p[j]) % Q , i});
                L[p[j]] = i;
                while (x % p[j] == 0)
                    x /= p[j];
            }
        }
        if (x > 1) {
            opt.push_back((query){L[x] , (LL)(x - 1) * inv(x) % Q , i});
            L[x] = i;
        }
    }
    sort(opt.begin() , opt.end());
    scanf("%d" , &m);
    for (int i = 0 ; i < m ; ++ i) {
        scanf("%d%d" , &q[i].l , &q[i].r);
        q[i].id = i;
    }
    sort(q , q + m);
    for (int i = 1 ; i <= n ; ++ i)
        c[i] = 1;
    for (int i = 0 , j = 0 ; i < m ; ++ i) {
        while (j < opt.size() && opt[j].l < q[i].l) {
            for (int k = opt[j].id ; k <= n ; k += k & -k)
                c[k] = (LL)c[k] * opt[j].r % Q;
            ++ j;
        }
        int A = s[q[i].r] , B = s[q[i].l - 1];
        for (int k = q[i].r ; k > 0 ; k -= k & -k)
            A = (LL)A * c[k] % Q;
        for (int k = q[i].l - 1 ; k > 0 ; k -= k & -k)
            B = (LL)B * c[k] % Q;
        res[q[i].id] = (LL)A * inv(B) % Q;
    }
    for (int i = 0 ; i < m ; ++ i)
        printf("%d\n" , res[i]);
    return 0;
}