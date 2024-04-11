#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

ll mod = 1000000007;

int main() {
    ll Q; cin >> Q;
    Pr sum[Q+1],used[Q+1],data[Q+1];
    rep(i,Q+1){
        sum[i] = make_pair(0LL,0LL); used[i] = make_pair(0LL,0LL);
    }
    ll logQ = 0; ll ba = 1;
    while(ba<=Q){
        logQ++; ba *= 2;
    }
    int anc[Q+1][logQ+1];
    rep(i,Q+1){
        rep(j,logQ+1){
            anc[i][j] = -1;
        }
    }
    ll a,c; cin >> a >> c;
    sum[0] = make_pair(a,a*c);
    data[0] = make_pair(a,c);
    rep(i,Q){
        ll t; cin >> t;
        if(t==1){
            int k = i+1; int p; cin >> p >> a >> c;
            auto[s,t] = sum[p];
            sum[k] = make_pair(s+a,t+a*c);
            //cout << k << " " << sum[k].first << " " << sum[k].second << endl;
            data[k] = make_pair(a,c);
            anc[k][0] = p;
            rep(j,logQ){
                if(anc[k][j]==-1) break;
                anc[k][j+1] = anc[anc[k][j]][j];
            }
        }
        if(t==2){
            ll v,w; cin >> v >> w;
            int vn = v;
            for(int j=logQ;j>=0;j--){
                if(anc[vn][j]==-1) continue;
                if(used[anc[vn][j]].first>0) continue;
                vn = anc[vn][j];
            }
            int par = vn;
            if(vn!=0&&used[vn].first==0) par = anc[vn][0];
            auto[amin,cmin] = used[par];
            //cout << amin << " " << cmin << endl;
            ll areq = w+amin;
            vn = v;
            for(int j=logQ;j>=0;j--){
                if(anc[vn][j]==-1) continue;
                if(sum[anc[vn][j]].first<areq) continue;
                vn = anc[vn][j];
            }
            Pr ans;
            if(sum[vn].first>=areq){
                ll red = (sum[vn].first - areq)*(data[vn].second);
                ans = make_pair(w,sum[vn].second-cmin-red);
                used[vn] = make_pair(areq,ans.second+cmin);
                //cout << vn << " " << used[vn].first << " " << used[vn].second << endl;
            }
            else{
                ans = make_pair(sum[vn].first-amin,sum[vn].second-cmin);
                used[vn] = sum[vn];
            }
            while(anc[vn][0]>=0&&vn!=par){
                vn = anc[vn][0];
                used[vn] = sum[vn];
                if(vn==par) break;
            }
            cout << ans.first << " " << ans.second << endl;
        }
    }
    
    //cout << ans << endl;
}