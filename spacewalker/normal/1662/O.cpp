#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> cord;
void solve() {
    int n;cin>>n;
    set<pair<cord,cord>> forbidden;
    for (int i = 0; i < n; i ++) {
        char ch;cin>>ch;
        if (ch == 'C') {
            int r, t1,t2;cin>>r>>t1>>t2;
            if (t2 < t1) t2 += 360;
            for (int i = t1; i < t2; i++) {
                int deg = i%360;
                cord c1 = {r-1, (r-1 == 0)? 0: deg};
                cord c2 = {r, deg};
                forbidden.insert({c1,c2});
                forbidden.insert({c2,c1});
            }
        } else {
            int r1,r2,theta;
            cin>>r1>>r2>>theta;
            for (int i = r1; i < r2; i++) {
                int bef = (theta == 0) ? 359: theta-1;
                cord c1 = {i, bef};
                cord c2 = {i, theta};
                forbidden.insert({c1,c2});
                forbidden.insert({c2,c1});
            }
        }
    }
    map<cord, vector<cord>> adj;
    cord origin = {0,0};
    for (int i = 0; i < 360; i++) {
        cord nxt = {1, i};
        if (forbidden.find({origin, nxt}) == forbidden.end()) {
            adj[origin].push_back(nxt);
            adj[nxt].push_back(origin);
        }
    }
    vector<int> udir = {0,0,-1,1};
    vector<int> vdir = {1,-1,0,0};
    for (int r = 1; r <= 20; r++) {
        for (int deg = 0; deg < 360; deg++) {
            cord u = {r, deg};
            for (int z = 0; z < 4; z++) {
                int nr = r + udir[z];
                int nd = (deg + vdir[z] + 360)%360;
                if (nr == 0 || nr == 21) continue;
                cord v = {nr,nd};
                if (forbidden.find({u,v}) == forbidden.end()) {
                    adj[u].push_back(v);
                }
            }
        }
    }
    queue<cord> q;
    set<cord> vis;
    vis.insert({0,0});
    q.push({0,0});
    while (!q.empty()) {
        auto u = q.front();q.pop();
        for (auto v: adj[u]) {
            if (vis.find(v) != vis.end()) continue;
            vis.insert(v);
            q.push(v);
        }
    }
    for (int i = 0; i < 360; i++) {
        if (vis.find({20,i}) != vis.end()) {
            cout<<"YES\n";return;
        }
    }
    cout<<"NO\n";
}


int main() {
    int tc;cin>>tc;
    for (int i= 0; i < tc; i++) {

        solve();
    }
    

}