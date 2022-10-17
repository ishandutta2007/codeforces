#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int diff(int a, int b) { return (a + MOD - b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int mpow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(b, mpow(b, e - 1));
    return mpow(prod(b, b), e/2);
}

const int MAXV = 15000;

int fact[MAXV];
int finv[MAXV];

int ncr(int n, int r) {
    if (r > n) return 0;
    return prod(fact[n], prod(finv[n-r], finv[r]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    fact[0] = 1;
    finv[0] = 1;
    for (int i = 1; i < MAXV; i++) {
        fact[i] = prod(i, fact[i-1]);
        finv[i] = mpow(fact[i], MOD - 2);
    }

    int N;
    string str;
    cin >> N >> str;

    vi len(N + 1);
    vvi let(26, vi(N + 1));
    vvi dp(N + 1, vi(N + 1));

    dp[0][0] = 1;
    len[0] = 1;

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int l = N; l >= 1; l--) {
            int c = str[i-1] - 'a';
            dp[i][l] = diff(len[l-1], 
                    sum(let[c][l-1], let[c][l]));

            len[l] = sum(len[l], dp[i][l]);
            let[c][l] = sum(let[c][l], dp[i][l]);

            ans = sum(ans, prod(dp[i][l], ncr(N - 1, l - 1)));
        }
    }

    cout << ans << endl;
    return 0;
}