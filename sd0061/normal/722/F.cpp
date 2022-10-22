#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int m , s;

struct opt {
    int x , r , l , p;
    bool operator < (const opt& R) const {
        if (x != R.x) {
            return x < R.x;
        }
        return r < R.r;
    }
}a[N];
int res[N] , LOG[N];

void exgcd(LL x , LL y , LL& a , LL& b) {
    if (y == 0) {
        a = 1 , b = 0;
    } else {
        exgcd(y , x % y , b , a);
        b -= (x / y) * a;
    }
}

LL modinverse(LL x , LL Q) {
    LL a , b;
    exgcd(x , Q , a , b);
    ///assert((LL)a * x + (LL)b * Q == 1);
    return (a % Q + Q) % Q;
}
pair<LL , LL> merge(pair<LL , LL> A , pair<LL , LL> B) {
    if (!A.first || !B.first) return {0 , 0};
    if (A.first < B.first) swap(A , B);
    LL b = (B.second - A.second % B.first + B.first) % B.first;
    LL a = A.first % B.first , c = B.first , d = __gcd(a , c);
    if (b % d != 0) {
        return make_pair(0 , 0);
    } else {
        a /= d , b /= d , c /= d;
        LL q = modinverse(a % c , c);
        b = b * q % c;
        LL mod = A.first * c;
        LL rest = (A.first * b + A.second) % mod;
        return make_pair(mod , rest);
    }
}

pair<LL , LL> f[17][N];
pair<LL , LL> get(int l , int r) {
    int j = LOG[r - l + 1];
    return merge(f[j][l] , f[j][r - (1 << j) + 1]);
}

void work(int l , int r) {
    int val = a[l].x , n = r - l;
    for (int i = 0 ; i < n ; ++ i) {
        f[0][i] = {a[l + i].l , a[l + i].p};
    }
    for (int j = 1 ; 1 << j <= n ; ++ j) {
        for (int i = 0 ; i + (1 << j) - 1 < n ; ++ i) {
            f[j][i] = merge(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
        }
    }
    for (int i = 0 , j = 0 ; i < n ; ++ i) {
        while (j < n && get(i , j).first != 0) {
            ++ j;
        }
        res[val] = max(res[val] , j - i);
    }

}

int main() {
    int n;
    scanf("%d%d" , &n , &m);
    for (int i = 2 ; i < N ; ++ i) {
        LOG[i] = LOG[i >> 1] + 1;
    }
    for (int i = 0 ; i < n ; ++ i) {
        int k;
        scanf("%d" , &k);
        for (int j = 0 ; j < k ; ++ j) {
            int x;
            scanf("%d" , &x);
            a[s ++] = (opt){x , i , k , j};
        }
    }
    sort(a , a + s);
    for (int i = 0 ; i < s ; ) {
        int j = i;
        while (j < s && a[i].x == a[j].x && a[j].r - a[i].r == j - i) {
            ++ j;
        }
        //cout << i << ' ' << j << endl;
        work(i , j);
        i = j;
    }
    for (int i = 1 ; i <= m ; ++ i) {
        printf("%d\n" , res[i]);
    }
}