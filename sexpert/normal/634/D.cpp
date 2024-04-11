#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

map<int, vector<int>> start, finish;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d, n, m;
    cin >> d >> n >> m;
    multiset<int> costs;
    vector<int> points;
    for(int i = 0; i < m; i++) {
        int x, p;
        cin >> x >> p;
        int lo = max(0, x - n), hi = min(x, d - n);
        start[lo].push_back(p);
        finish[hi].push_back(p);
        points.push_back(lo);
        points.push_back(hi);
    }
    if(n >= d) {
        cout << "0\n";
        return 0;
    }
    points.push_back(0);
    points.push_back(d - n);
    sort(points.begin(), points.end());
    auto it = unique(points.begin(), points.end());
    points.erase(it, points.end());
    ll ans = 0;
    for(int i = 0; i < points.size(); i++) {
        int pos = points[i];
        //cout << pos << " ";
        //cout << "start at " << pos << '\n';
        if(i > 0) {
            ll m = *costs.begin();
            //cout << m << endl;
            ans += m * (points[i] - points[i - 1]);
        }
        for(auto x : start[pos]) {
            //cout << x << " ";
            costs.insert(x);
        }
        //cout << '\n';
        //cout << "end at " << pos << '\n';
        for(auto x : finish[pos]) {
            //cout << x << " ";
            costs.erase(costs.find(x));
        }
        //cout << '\n';
        if(i < (int)points.size() - 1 && costs.empty()) {
            cout << "-1\n";
            return 0;
        }
    }
    //cout << '\n';
    cout << ans << '\n';
}