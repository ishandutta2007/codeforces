#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi ct(M, N/M);
    for (int v = N/M*M+1; v <= N; v++)
        ct[v % M]++;

    vi sqct(M, 0);
    for (int r = 0; r < M; r++) {
        sqct[r * r % M] += ct[r];
    }

    ll ans = 0;
    for (int r = 0; r < M; r++) {
        ans += sqct[r] * 1ll * sqct[r ? (M-r) : r];
    }
    cout << ans << endl;

    return 0;
}