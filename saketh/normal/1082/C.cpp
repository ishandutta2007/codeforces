#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vvi skills(M);
    for (int i = 0; i < N; i++) {
        int s, r;
        cin >> s >> r;
        skills[s-1].push_back(r);
    }

    for (int s = 0; s < M; s++) {
        sort(all(skills[s]), greater<int>());
    }

    vi score(N + 1);
    for (int s = 0; s < M; s++) {
        int tot = 0;
        for (int i = 0; i < skills[s].size(); i++) {
            tot += skills[s][i];
            if (tot > 0) {
                score[i] += tot;
            }
        }
    }

    int ans = 0;
    for (int v : score)
        ans = max(ans, v);
    cout << ans << endl;

    return 0;
}