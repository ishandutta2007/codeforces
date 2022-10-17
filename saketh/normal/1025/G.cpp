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
int prod(int a, int b) { return a * 1ll * b % MOD; }
int mod_pow(int b, int e) {
    if (!e) return 1;
    if (e&1) return prod(b, mod_pow(b, e - 1));
    return mod_pow(prod(b, b), e/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi ch(N);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p != -1)
            ch[p - 1]++;
    }

    int ans = sum(mod_pow(2, N - 1), MOD - 1);
    for (int v : ch) {
        int sub = sum(mod_pow(2, v), MOD - 1);
        ans = sum(ans, MOD - sub);
    }
    cout << ans << endl;

    return 0;
}