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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi coord(2 * N);
    for (int i = 0; i < 2 * N; i++)
        cin >> coord[i];

    sort(all(coord));

    ll ans = ll(coord[N-1] - coord[0]) * ll(coord[2*N-1] - coord[N]);
    for (int i = 1; i + N < 2 * N; i++) {
        ll cand = ll(coord[2*N-1] - coord[0]) * ll(coord[i+N-1] - coord[i]);
        ans = min(ans, cand);
    }
    cout << ans << endl;

    return 0;
}