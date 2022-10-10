#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ii> v;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end(), [&](ii a, ii b) { return a.second - a.first > b.second - b.first; });
    int ans = 0;
    set<ii> segs;
    for(int i = 0; i < n; i++) {
        auto it = segs.lower_bound({v[i].first, v[i].first});
        if(it == segs.begin() || (--it)->second <= v[i].second)
            segs.insert(v[i]);
        else
            ans++;
    }
    cout << ans << endl;
}