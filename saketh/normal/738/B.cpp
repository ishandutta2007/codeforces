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

    int N, M;
    cin >> N >> M;

    vi rmin(N, INT_MAX), rmax(N, -1);
    vi cmin(M, INT_MAX), cmax(M, -1);

    vector<pair<int, int>> empty;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int v;
            cin >> v;

            if (v) {
                rmin[r] = min(rmin[r], c);
                rmax[r] = max(rmax[r], c);
                cmin[c] = min(cmin[c], r);
                cmax[c] = max(cmax[c], r);
            } else {
                empty.emplace_back(r, c);
            }
        }
    }

    int ans = 0;
    for (auto p : empty) {
        if (p.first > cmin[p.second]) ans++;
        if (p.first < cmax[p.second]) ans++;
        if (p.second > rmin[p.first]) ans++;
        if (p.second < rmax[p.first]) ans++;
    }
    cout << ans << endl;

    return 0;
}