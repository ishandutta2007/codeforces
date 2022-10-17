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

    vi cost(N);
    for (int i = 0; i < N; i++)
        cin >> cost[i];

    vi succ(N);
    for (int i = 0; i < N; i++) {
        cin >> succ[i];
        succ[i]--;
    }

    vb visit(N);
    vi index(N);
    vi order;
    int ans = 0;

    for (int i = 0, j; i < N; i++) {
        int atb = order.size();

        for (j = i; !visit[j]; j = succ[j]) {
            visit[j] = true;
            index[j] = order.size();
            order.push_back(j);
        }

        if (index[j] >= atb) {
            int trap = INT_MAX;
            for (int k = index[j]; k < order.size(); k++)
                trap = min(trap, cost[order[k]]);
            ans += trap;
        }
    }

    cout << ans << endl;
    return 0;
}