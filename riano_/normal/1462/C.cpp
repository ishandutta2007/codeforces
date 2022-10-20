#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N; cin >> N;
    rep(ii,N){
        ll x; cin >> x;
        set<int> used;
        vector<int> ans;
        bool sk = false;
        while(x>0){
            if(used.size()==9){
                cout << -1 << endl; 
                sk = true; break;
            }
            rep(i,9){
                if(used.count(9-i)){
                    continue;
                }
                if(x<(9-i)){
                    continue;
                }
                ans.push_back(9-i); used.insert(9-i);
                x -= (9-i); break;
            }
        }
        if(sk) continue;
        rep(i,ans.size()) cout << ans[ans.size()-1-i];
        cout << endl;
    }
    //cout << ans << endl;
}