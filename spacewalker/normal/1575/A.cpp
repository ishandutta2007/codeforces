#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> ii;
#define rep(i,x,y) for (i = (x); i < (y); i++)
 
int main() {
    int n,m; cin >> n >> m;
    vector<ii> v;
    int i;
    rep(i,0,n) {
        string d; cin >> d;
        v.push_back({d, i});
    }
    sort(v.begin(), v.end(), [&](ii &p, ii &q) {
        rep(i,0,m) {
            if (p.first[i] != q.first[i]) {
                if (i % 2 == 0) {
                    return p.first[i] < q.first[i];
                } else {
                    return p.first[i] > q.first[i];
                }
            }
        }
        return p.second < q.second;
    });
    for (auto &j : v) cout << j.second + 1 << ' ';

}