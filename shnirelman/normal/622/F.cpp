//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int norm1(int a) {
//    cout << "norm " << a << endl;
    while(a < 0)
        a += M;
    while(a >= M)
        a -= M;

//    cout << "norm2 " << a << endl;
    return a;
}

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
//    cout << "mul " << a << ' ' << b << ' ' << norm(a * 1ll * b % M) << endl;
//    return a * 1ll * b % M;
//    int res =
//    cout << "mul " << a << ' ' << b << ' ' << res << endl;
    return norm1(a * 1ll * b % M);;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

//    cout << "pow2 " << n << ' ' << k << ' ' << pw << ' ' << mul(pw, n) << ' ' << norm(mul(pw, n)) << endl;

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(norm1(n), M - 2);
}

int ainv[N];

/*
*/

int y[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    cout << norm(2) << endl;
//    cout << pow2(2, 1) << endl;
//    return 0;

    int n, k;
    cin >> n >> k;

    y[1] = 1;
    for(int i = 2; i <= k + 2; i++) {
        y[i] = sum(y[i - 1], pow2(i, k));
//        cout << "y " << i << ' ' << y[i] << endl;
    }

    for(int i = 1; i < N; i++)
        ainv[i] = inv(i);

    if(n <= k + 2) {
        cout << y[n] << endl;
        return 0;
    }

    int ans = 0;

    int nom = 1;
    int denom = 1;
    for(int i = 2; i <= k + 2; i++) {
        nom = mul(nom, n - i);
        denom = mul(denom, -ainv[i - 1]);
    }

//    cout << nom << ' ' << denom << ' ' << y[1] << ' ' << inv(denom) << endl;

    ans = mul(mul(nom, denom), y[1]);

//    cout << ans << endl;

    for(int i = 2; i <= k + 2; i++) {
        nom = mul(nom, n - i + 1);
        nom = mul(nom, inv(n - i));

//        if(i == k + 2)
//            denom = dif(0, denom);
//        else {
            denom = mul(denom, ainv[i - 1]);
            denom = mul(denom, i - k - 3);
//            denom = dif(0, denom);
//        }


        ans = sum(ans, mul(mul(nom, denom), y[i]));
//        cout << nom << ' ' << denom << ' ' << y[i] << ' ' << inv(denom) << endl;
//        cout << mul(mul(nom, inv(denom)), y[i]) << endl;
    }

    cout << ans << endl;
}