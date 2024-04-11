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

    vi stax(N);
    for (int i = 0; i < N; i++) {
        cin >> stax[i];
    }

    sort(all(stax), greater<int>());

    int cov = stax.front();
    ll ans = 0;

    for (int i = 0; i < stax.size(); i++) {
        int pick = 1;
        if (i+1 < stax.size())
            pick = max(pick, cov - stax[i+1]);
        else
            pick = max(pick, cov);
        ans += pick;
        cov -= pick;
    }

    ll tot = 0;
    for (int v : stax)
        tot += v;

    cout << tot - ans << endl;
    return 0;
}