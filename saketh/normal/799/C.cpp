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

const int MINF = INT_MIN/2;

vi arrange(vector<pair<int, int>> &fount) {
    sort(all(fount));

    vi maxes(fount.size());
    for (int i = 0; i < fount.size(); i++) {
        if (i) maxes[i] = max(fount[i].second, maxes[i-1]);
        else maxes[i] = fount[i].second;
    }

    return maxes;
}

int get_best(vector<pair<int, int>> &fount, vi &maxes, int funds, int inx_max) {
    if (fount.size() == 0 || inx_max < 0) return MINF;

    pair<int, int> key = { funds + 1, -1 };
    auto it = lower_bound(all(fount), key);

    if (it == fount.begin()) return MINF;
    it = prev(it);

    int which = it - fount.begin();
    which = min(which, inx_max);
    return maxes[which];
}

int solve(vector<pair<int, int>> &fount, vi &maxes, int funds) {
    int ans = 0;

    for (int i = 0; i < fount.size(); i++) {
        if (fount[i].first > funds) continue;
        ans = max(ans, fount[i].second + get_best(fount, maxes, funds - fount[i].first, i - 1));
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, C, D;
    cin >> N >> C >> D;

    vector<pair<int, int>> coins, diamonds;

    for (int i = 0; i < N; i++) {
        int beauty, cost;
        char type;

        cin >> beauty >> cost >> type;

        if (type == 'C') {
            coins.emplace_back(cost, beauty);
        } else {
            diamonds.emplace_back(cost, beauty);
        }
    }

    vi cmax = arrange(coins),
       dmax = arrange(diamonds);

    int sep = max(0, get_best(coins, cmax, C, INT_MAX)
                     + get_best(diamonds, dmax, D, INT_MAX));

    int just_coins = solve(coins, cmax, C);
    int just_diamonds = solve(diamonds, dmax, D);

    cout << max( { sep, just_coins, just_diamonds } ) << endl;
    return 0;
}