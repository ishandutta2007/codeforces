#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int sat[1 << 9];
int m1[1 << 9];
int m2[1 << 9];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0, F; i < N; i++) {
        cin >> F;
        int like = 0;
        for (int j = 0, b; j < F; j++) {
            cin >> b;
            like |= 1 << (b - 1);
        }

        for (int m = 0; m < (1 << 9); m++)
            if ((m | like) == m)
                sat[m]++;
    }

    memset(m1, 0xff, sizeof(m1));
    memset(m2, 0xff, sizeof(m1));

    vi prices(M);
    for (int i = 0, R; i < M; i++) {
        cin >> prices[i] >> R;
        int have = 0;
        for (int j = 0, a; j < R; j++) {
            cin >> a;
            have |= 1 << (a - 1);
        }

        if (m1[have] == -1 || prices[i] < prices[m1[have]]) { m2[have] = m1[have]; m1[have] = i; }
        else if (m2[have] == -1 || prices[i] < prices[m2[have]]) m2[have] = i;
    }

    pair<int, int> best = { 0, INT_MAX };
    int i1 = -1, i2 = -1;

    for (int a = 0; a < (1 << 9); a++) if(m1[a] != -1) {
        for (int b = a + 1; b < (1 << 9); b++) if (m1[b] != -1) {
            pair<int, int> cand = { sat[a|b], prices[m1[a]] + prices[m1[b]] };
            if (cand.first > best.first || (cand.first == best.first && cand.second < best.second)) {
                i1 = m1[a];
                i2 = m1[b];
                best = cand;
            }
        }

        if (m2[a] != -1) {
            pair<int, int> cand = { sat[a], prices[m1[a]] + prices[m2[a]] };
            if (cand.first > best.first || (cand.first == best.first && cand.second < best.second)) {
                i1 = m1[a];
                i2 = m2[a];
                best = cand;
            }
        }
    }

    cout << i1 + 1 << " " << i2 + 1 << endl;

    return 0;
}