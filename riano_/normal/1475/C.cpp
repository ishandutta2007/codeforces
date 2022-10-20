#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    ll N; cin >> N;
    rep(i,N){
        ll a,b,k; cin >> a >> b >> k;
        ll cb[a],cg[b];
        rep(j,a){
            cb[j] = 0;
        }
        rep(j,b){
            cg[j] = 0;
        }
        vector<Pr> pr;
        ll ans = 0;
        rep(j,k){
            ll c; cin >> c; c--;
            cb[c]++;
            pr.push_back(make_pair(c,0LL));
        }
        rep(j,k){
            ll d; cin >> d; d--;
            cg[d]++;
            auto[c,e] = pr[j];
            pr[j] = make_pair(c,d);
        }
        rep(j,k){
            auto[c,d] = pr[j];
            ans += (k+1-cb[c]-cg[d]);
            //cout << ans << endl;
        }
        cout << ans/2 << endl;
    }
    //cout << ans << endl;
}