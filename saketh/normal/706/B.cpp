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

    int N;
    cin >> N;

    vector<pair<int, int>> vals;

    for (int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        vals.emplace_back(cost, -1);
    }

    int Q;
    cin >> Q;
    
    vi ans(Q);

    for (int i = 0; i < Q; i++) {
        int manei;
        cin >> manei;
        vals.emplace_back(manei, i);
    }

    sort(all(vals));

    int avail = 0;
    for (auto e : vals) {
        if (e.second == -1)
            avail++;
        else
            ans[e.second] = avail;
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";

    return 0;
}