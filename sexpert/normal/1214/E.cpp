#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<ii> req, ans;
    vector<int> path;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        req.push_back({d, i});
    }
    sort(req.rbegin(), req.rend());
    for(auto p : req)
        path.push_back(2*p.second);
    for(int i = 0; i < n - 1; i++)
        ans.push_back({path[i], path[i + 1]});
    int ctr = 0;
    for(auto r : req) {
        int to = ctr + r.first;
        ctr++;
        ans.push_back({path[to - 1], 2*r.second - 1});
        if(to == path.size())
            path.push_back(2*r.second - 1);
    }
    for(auto p : ans)
        cout << p.first << " " << p.second << '\n';
}