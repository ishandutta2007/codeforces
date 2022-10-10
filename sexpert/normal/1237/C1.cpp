#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

map<int, set<array<int, 3>>> pts;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> coords;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pts[x].insert({y, z, i + 1});
        coords.insert(x);
    }
    vector<array<int, 4>> rem;
    for(auto x : coords) {
        auto s = pts[x];
        while(s.size() >= 2) {
            array<int, 3> p = *s.begin();
            auto it = s.begin();
            ++it;
            auto q = *it;
            if(q[0] == p[0]) {
                cout << p[2] << " " << q[2] << '\n';
                s.erase(p);
                s.erase(q);
                continue;
            }
            auto po = s.lower_bound({q[0], p[1]});
            if(po == s.end() || (*po)[0] != q[0])
                --po;
            auto r = *po;
            cout << p[2] << " " << r[2] << '\n';
            s.erase(p);
            s.erase(r);
        }
        if(s.size()) {
            auto p = *s.begin();
            rem.push_back({x, p[0], p[1], p[2]});
        }
    }
    sort(rem.begin(), rem.end());
    for(int i = 0; i < rem.size()/2; i++)
        cout << rem[2*i][3] << " " << rem[2*i + 1][3] << '\n';
}