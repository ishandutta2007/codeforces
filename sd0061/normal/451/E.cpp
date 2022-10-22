#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 100005;
int n ; LL a[20];
LL Q = 1e9 + 7 , s;
LL inv(LL x) {return x == 1 ? 1 : (Q - Q / x) * inv(Q % x) % Q;}

LL C(LL A , LL B) {
    if (A < 0 || B > A || B < 0) return 0;
    LL res = 1;
    for (LL i = A ; i > A - B ; -- i)
        res *= i % Q , res %= Q;
    for (LL i = 1 ; i <= B ; ++ i)
        res *= inv(i) , res %= Q;
    return res;
}

void work() {
    int i , j ;
    LL ans = 0;
    cin >> n >> s;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (i = 0 ; i < 1 << n ; ++ i) {
        int x = 0 ; LL y = 0;
        for (j = 0 ; j < n ; ++ j)
            if (i >> j & 1)
                ++ x , y += a[j];
        if (x & 1)
            ans -= C(s - y - x + n - 1 , n - 1);
        else
            ans += C(s - y - x + n - 1 , n - 1);
        ans += Q , ans %= Q;
    }
    cout << ans << endl;
}

int main(){
    work();
    return 0;
}