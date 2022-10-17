#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    int poss = 0;

    vector<double> prob(N);
    for (int i = 0; i < N; i++) {
        cin >> prob[i];
        if (prob[i] > 1e-9)
            poss++;
    }

    K = min(K, poss);

    vector<double> reach(1 << N);
    reach[0] = 1;

    vector<double> ans(N);

    for (int m = 0; m < reach.size(); m++) {
        double tot = 0;
        vector<int> miss;

        for (int i = 0; i < N; i++) {
            if (((m >> i)&1) == 0) {
                miss.push_back(i);
                tot += prob[i];
            } else if (__builtin_popcount(m) == K) {
                ans[i] += reach[m];
            }
        }

        if (tot < 1e-9) continue;

        for (int v : miss) {
            int mm = m | (1 << v);
            reach[mm] += reach[m] * prob[v] / tot;
        }
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}