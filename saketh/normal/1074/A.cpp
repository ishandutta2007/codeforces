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

    vi vert(N);
    for (int i = 0; i < N; i++) {
        cin >> vert[i];
    }
    sort(all(vert));
    vert.push_back(1000000000);

    vector<array<int, 3>> horiz(M);
    for (int i = 0; i < M; i++) {
        cin >> horiz[i][1] >> horiz[i][2] >> horiz[i][0];
    }
    sort(all(horiz));

    vi hlen;
    for (int i = 0, j; i < M; i = j) {
        int fgap = 0;
        for (j = i; j < M && horiz[j][0] == horiz[i][0]; j++) {
            if (horiz[j][1] == fgap + 1)
                fgap = horiz[j][2];
        }
        hlen.push_back(fgap);
    }

    sort(all(hlen));

    int ans = INT_MAX;
    for (int rv = 0; rv <= N; rv++) {
        ans = min(ans, rv + int(hlen.end() - lower_bound(all(hlen), vert[rv])));
    }
    cout << ans << endl;

    return 0;
}