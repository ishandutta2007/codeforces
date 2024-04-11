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
    rep(ii,N){
        ll n,m; cin >> n >> m;
        ll a[n],b[n];
        rep(i,n){
            cin >> a[i];
        }
        rep(i,n){
            cin >> b[i];
        }
        vector<ll> reg,imp;
        rep(i,n){
            if(b[i]==1){
                reg.push_back(a[i]);
            }
            else{
                imp.push_back(a[i]);
            }
        }
        sort(reg.begin(),reg.end()); reverse(reg.begin(),reg.end());
        sort(imp.begin(),imp.end()); reverse(imp.begin(),imp.end());
        ll cl = 0,com = 0;
        int j=0; int k = 0;
        while(cl<m){
            if(j==(imp.size())){
                if(k==(reg.size())){
                    break;
                }
                cl += reg[k]; com += 1; k++;
            }
            else{
                cl += imp[j]; com += 2; j++;
            }
        }
        if(cl<m){
            cout << -1 << endl; continue;
        }
        ll ans = com;
        while(j>0){
            j--;
            cl -= imp[j]; com -= 2;
            while(cl<m){
                if(k==(reg.size())) break;
                cl += reg[k]; com += 1; k++;
            }
            if(cl<m) break;
            ans = min(ans,com);
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}