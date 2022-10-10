#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

map<ii, int> pop;

int main() {
    int n, s;
    cin >> n >> s;
    vector<ii> v;
    for(int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        v.push_back({x, y});
        pop[{x, y}] = p;
    }
    sort(v.begin(), v.end(), [] (ii a, ii b) {return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second; });
    for(int i = 0; i < n; i++) {
        s += pop[v[i]];
        if(s >= 1000000) {
            cout << fixed << setprecision(20) << hypot(v[i].first, v[i].second) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}