#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<Pr>>;

const ll mod = 1000000007;


//compression 
class compress {
public:
    map<ll,ll> label;
    vector<ll> inverse;
    set<ll> num;
    bool ready;
    compress(int a){
        num.insert(0);
        label[0] = 0;
        inverse.push_back(0);
        ready = false;
    }

    //x
    void add(ll x){
        num.insert(x); ready = false;
    }

    //sort
    void labeling(void){
        inverse.clear();
        int k = 0;
        for(ll x:num){
            inverse.push_back(x);
            label[x] = k; k++;
        }
    }

    //x
    ll lab(ll x){
        if(!ready){
            labeling(); ready = true;
        }
        return label[x];
    }

    //i
    ll inv(ll i){
        if(!ready){
            labeling(); ready = true;
        }
        return inverse[i];
    }

    //size
    ll size(void){
        if(!ready){
            labeling(); ready = true;
        }
        return inverse.size();
    }

};
    

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N;
        //cout << "-------" << "\n";
        //main
        compress comp(1); //1
        //  comp.add(x);
        //
        int l[N],r[N];
        rep(i,N){
            cin >> l[i] >> r[i];
            comp.add(l[i]); comp.add(r[i]);
        }
        int lc[N],rc[N];
        int M = comp.size();
        rep(i,N){
            lc[i] = comp.lab(l[i]); rc[i] = comp.lab(r[i]);
        }

        int dp[M][M];
        rep(i,M){
            rep(j,M) dp[i][j] = 0;
        }

        vector<vector<ll>> st(M);
        rep(i,N){
            st[rc[i]].push_back(lc[i]);
            //dp[lc[i]][rc[i]]++;
        }

        for(int d=0;d<M;d++){
            rep(i,M){
                if(i+d>=M) break;
                if(d>=1){
                    dp[i][i+d] = max(dp[i][i+d],dp[i][i+d-1]+dp[i+d][i+d]);
                    dp[i][i+d] = max(dp[i][i+d],dp[i][i]+dp[i+1][i+d]);
                }
                int add= 0;
                for(ll x:st[i+d]){
                    //cout << i+d << " " << x << endl;
                    
                    if(x>i){
                        dp[i][i+d] = max(dp[i][i+d],dp[i][x-1]+dp[x][i+d]);
                    }
                    else if(x==i){
                        add++;
                    }
                }
                dp[i][i+d] += add;
            }
        }
        // if(ii==3){
        //     cout << dp[2][5] << endl;
        //     cout << dp[6][8] << endl;
        //     cout << dp[2][8] << endl;
        // }
        ll ans = dp[0][M-1];
        
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}