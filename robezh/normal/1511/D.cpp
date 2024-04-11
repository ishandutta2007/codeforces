#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<pii> G[30];
vi res;

void euler(int v){
    while(G[v].size()){
        auto e = *G[v].begin();
        int nxt = e.first, eid = e.second;
        G[v].erase(G[v].begin());
//        if(G[nxt].find({v, eid}) != G[nxt].end()) {
//            G[nxt].erase({v, eid});
//        }
        euler(nxt);
    }
    res.push_back(v);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int eid = 0;
    rep(i, 0, k) {
        rep(j, i, k) {
            int cid = eid++;
            G[i].insert({j, cid});
            if(i != j) G[j].insert({i, cid});
        }
    }
    euler(0);
    res.pop_back();
//    cout << sz(res) << endl;
    for(int i = 0; i < n; i++) {
        cout << (char)(res[i % sz(res)] + 'a') ;
    }
    cout << endl;

}