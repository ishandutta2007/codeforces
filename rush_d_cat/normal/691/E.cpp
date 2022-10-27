#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
//#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> pii;
typedef long long LL;
const LL INF = 1e16;
const LL MOD = 1000000007;
const int N = 100+10;

int count(LL x) {
    int ans = 0;
    while (x) {
        ans += (x&1);
        x >>= 1;
    }
    return ans;
}

LL n, k;
LL a[N];
int mp[N][N];

struct Matrix {
    LL a[N][N];
};

Matrix mul(Matrix A, Matrix B) {
    Matrix C;
    memset(C.a, 0, sizeof(C.a));
    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n)
        (C.a[i][j] += A.a[i][k]*B.a[k][j]) %= MOD;
    return C;
}

Matrix mpow(Matrix A, LL x) {
    Matrix C;
    memset(C.a, 0, sizeof(C.a));
    if (x == 0) {
        rep(i, 1, n) C.a[i][i] = 1;
        return C;
    }
    C = mpow(A, x/2);
    if (x % 2)
        return mul(mul(C, C), A);
    return mul(C, C);
}

LL x[N];
void init() {
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, 1, n) {
        if (count(a[i]^a[j]) % 3 == 0)
            mp[i][j] = 1;
    }

    memset(x, 1, sizeof(x));

    Matrix A; memset(A.a, 0, sizeof(A.a));
    rep(i, 1, n) rep(j, 1, n) if (mp[i][j]) {
        A.a[j][i] = 1;
    }
    A = mpow(A, k-1);
    LL sum = 0;
    rep(i, 1, n) rep(j, 1, n)
        sum = (sum + A.a[i][j]) % MOD;

    cout << sum << endl;
}

int main() {
    init();
}