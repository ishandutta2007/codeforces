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

    vi dist(N + M);
    for (int i = 0; i < N + M; i++) {
        cin >> dist[i];
    }

    vi taxi(N + M);
    for (int i = 0; i < N + M; i++) {
        cin >> taxi[i];
    }

    const int INF = 1e9;

    vi users, cars;
    cars.push_back(-INF);
    for (int i = 0; i < N + M; i++) {
        if (taxi[i]) cars.push_back(dist[i]);
        else users.push_back(dist[i]);
    }
    cars.push_back(2*INF);

    vi ans(M + 2);
    for (int loc : users) {
        int which = lower_bound(all(cars), loc) - cars.begin();
        int c1 = cars[which] - loc;
        int c2 = loc - cars[which-1];
        if (c2 <= c1) {
            ans[which-1]++;
        } else {
            ans[which]++;
        }
    }

    for (int i = 1; i <= M; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}