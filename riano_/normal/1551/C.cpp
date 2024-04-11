#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;

int main() {
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        ll w[N][6];
        rep(i,N){
            rep(j,6){
                w[i][j] = 0;
            }
        }
        rep(i,N){
            string S; cin >> S;
            rep(j,5){
                rep(k,S.size()){
                    if((int)(S[k]-'a')==j) w[i][j]++;
                }
            }
            w[i][5] = S.size();
        }
        ll ans = 0;
        rep(i,5){
            vector<ll> d;
            rep(j,N){
                d.push_back(2*w[j][i]-w[j][5]);
            }
            sort(d.begin(),d.end()); reverse(d.begin(),d.end());
            ll cnt = 0,sum = 0;
            rep(i,N){
                if(sum+d[i]<=0) break;
                sum += d[i]; cnt++;
            }
            ans = max(ans,cnt);
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}