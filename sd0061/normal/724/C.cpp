#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n , m , K;

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
    assert((LL)a * x + (LL)b * Q == 1);
    return (a % Q + Q) % Q;
}

pair<LL , LL> mergemodulo(pair<LL , LL> A , pair<LL , LL> B) {
    if (A.first < B.first) {
        swap(A , B);
    }
    LL a = A.first % B.first;
    LL b = (B.second - A.second % B.first + B.first) % B.first;
    LL c = B.first , d = __gcd(a , c);
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

int main() {
    scanf("%d%d%d" , &n , &m , &K);
    for (int i = 0 ; i < K ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        int X[2] = {x , n + n - x};
        int Y[2] = {y , m + m - y};
        LL res = 1LL << 60;
        for (int j = 0 ; j < 2 ; ++ j) {
            for (int k = 0 ; k < 2 ; ++ k) {
                pair<LL , LL> P = mergemodulo({n + n , X[j]} , {m + m , Y[k]});
                if (P.first) {
                    res = min(P.second , res);
                }
            }
        }
        if (res == 1LL << 60) {
            puts("-1");
        } else {
            printf("%lld\n" , res);
        }
    }
}