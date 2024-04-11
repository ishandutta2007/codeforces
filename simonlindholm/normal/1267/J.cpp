#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int N;
    cin >> N;
    map<int, int> cats;
    int c;
    rep(i,0,N) cin >> c, cats[c]++;
    map<int, int> cur;
    trav(pa, cats) {
        int a = pa.second;
        map<int, int> costs;
        for (int k = 1; k <= a + 1; k++) {
            int cost;
            if (a % k == 0) cost = a / k;
            else if (a % k + a / k >= k - 1) cost = a / k + 1;
            else continue;
            costs[k] = cost;
        }
        if (cur.empty()) cur = costs;
        else {
            for (auto it = cur.begin(); it != cur.end();) {
                auto it2 = costs.find(it->first);
                if (it2 == costs.end()) cur.erase(it++);
                else it->second += it2->second, ++it;
            }
        }
    }
    int best = INT_MAX;
    trav(pa, cur) best = min(best, pa.second);
    cout << best << endl;
}

int main() {
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    rep(i,0,N) solve();
}