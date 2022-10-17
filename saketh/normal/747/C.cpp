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

    int N, Q;
    cin >> N >> Q;

    int A = N;
    vector<bool> avail(N, true);

    priority_queue<pair<int, int>> pq;

    int T;
    vi K(Q), D(Q);

    for (int q = 0; q < Q; q++) {
        cin >> T >> K[q] >> D[q];
        pq.push({-T, q - Q});
    }

    vi ans(Q, -1);
    while (!pq.empty()) {
        int time = -pq.top().first;
        int what = pq.top().second;
        pq.pop();

        if (what >= 0) {
            A++;
            avail[what] = true;
        } else if (K[what + Q] > A) {
            continue;
        } else {
            ans[what + Q] = 0;
            for (int i = 0; i < N && K[what + Q] > 0; i++) {
                if (!avail[i]) continue;
                avail[i] = false;
                A--;
                K[what + Q]--;
                pq.push({ -time - D[what + Q], i });
                ans[what + Q] += i + 1;
            }
        }
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
    return 0;
}