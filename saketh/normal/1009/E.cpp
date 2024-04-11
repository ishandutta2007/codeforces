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

const int MOD = 998244353;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi p2(N);
    p2[0] = 1;
    for (int i = 1; i < N; i++)
        p2[i] = prod(2, p2[i-1]);

    ll ans = 0;

    vi diff(N);
    for (int i = 0; i < N; i++) {
        cin >> diff[i];

        ll ways = 0;

        // The earliest possible occurence is a little different
        ways = p2[N - 1 - i];

        // The remaining ones work the same
        if (i < N - 1)
            ways = sum(ways, prod(N - i - 1, p2[N - 1 - i - 1]));

        ans = sum(ans, prod(diff[i], ways));
    }

    cout << ans << endl;
    return 0;
}