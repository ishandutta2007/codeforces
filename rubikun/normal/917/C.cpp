#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=120000005;
const ll INF=1LL<<60;
const int D=2005;
int state[1<<8],rstate[73];
ll subdp[73][D+15][73],dpdp[D+15][73];
ll dp[MAX/D][73];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int x,k,N,Q;cin>>x>>k>>N>>Q;
    vector<ll> c(k+1);
    for(int i=1;i<=k;i++) cin>>c[i];
    
    int bi=0;
    for(int bit=0;bit<(1<<k);bit++){
        if(__builtin_popcount(bit)==x){
            state[bit]=bi;
            rstate[bi]=bit;
            bi++;
        }
    }
    
    for(int i=0;i<bi;i++){
        for(int j=0;j<D+15;j++) for(int kk=0;kk<bi;kk++) subdp[i][j][kk]=INF;
        subdp[i][0][i]=0;
        
        for(int j=0;j<D;j++){
            for(int kk=0;kk<bi;kk++){
                if(subdp[i][j][kk]==INF) continue;
                int bit=rstate[kk];
                if(!(bit&1)) chmin(subdp[i][j+1][state[bit/2]],subdp[i][j][kk]);
                else{
                    for(int l=1;l<=k;l++){
                        if(bit&(1<<l)) continue;
                        chmin(subdp[i][j+1][state[(bit+(1<<l))/2]],subdp[i][j][kk]+c[l]);
                    }
                }
            }
        }
    }
    
    vector<pair<int,ll>> X(Q);
    vector<int> ng((N-x)/D);
    for(int i=0;i<Q;i++){
        int a,b;cin>>a>>b;
        a--;
        X[i]=mp(a,-b);
        for(int j=-1;j<=1;j++){
            if(0<=a/D+j&&a/D+j<si(ng)) ng[a/D+j]=true;
        }
    }
    
    for(int i=0;i<MAX/D;i++) for(int j=0;j<73;j++) dp[i][j]=INF;
    dp[0][0]=0;
    
    for(int t=0;t<=(N-x)/D;t++){
        if(t==(N-x)/D){
            vector<ll> change(3*D);
            for(int i=0;i<Q;i++){
                int a=X[i].fi,b=X[i].se;
                if(0<=a-t*D&&a-t*D<3*D) change[a-t*D]-=b;
            }
            
            for(int b=0;b<D+15;b++) for(int cc=0;cc<bi;cc++) dpdp[b][cc]=INF;
            
            for(int cc=0;cc<bi;cc++) dpdp[0][cc]=dp[t][cc];
            
            for(int j=0;j<(N-x)%D;j++){
                for(int kk=0;kk<bi;kk++){
                    if(dpdp[j][kk]==INF) continue;
                    int bit=rstate[kk];
                    if(!(bit&1)) chmin(dpdp[j+1][state[bit/2]],dpdp[j][kk]);
                    else{
                        for(int l=1;l<=k;l++){
                            if(bit&(1<<l)) continue;
                            ll tasu=change[j+l];
                            //cout<<bit<<" "<<((bit+(1<<l))/2)<<" "<<state[(bit+(1<<l))/2]<<endl;
                            chmin(dpdp[j+1][state[(bit+(1<<l))/2]],dpdp[j][kk]+c[l]+tasu);
                        }
                    }
                }
            }
            
            cout<<dpdp[(N-x)%D][0]<<endl;
            return 0;
        }
        if(!ng[t]){
            for(int a=0;a<bi;a++){
                for(int b=0;b<bi;b++){
                    chmin(dp[t+1][b],dp[t][a]+subdp[a][D][b]);
                }
            }
        }else{
            vector<ll> change(3*D);
            for(int i=0;i<Q;i++){
                int a=X[i].fi,b=X[i].se;
                if(0<=a-t*D&&a-t*D<3*D) change[a-t*D]-=b;
            }
            
            for(int b=0;b<D+15;b++) for(int cc=0;cc<bi;cc++) dpdp[b][cc]=INF;
            
            for(int cc=0;cc<bi;cc++) dpdp[0][cc]=dp[t][cc];
            
            for(int j=0;j<D;j++){
                for(int kk=0;kk<bi;kk++){
                    if(dpdp[j][kk]==INF) continue;
                    int bit=rstate[kk];
                    if(!(bit&1)) chmin(dpdp[j+1][state[bit/2]],dpdp[j][kk]);
                    else{
                        for(int l=1;l<=k;l++){
                            if(bit&(1<<l)) continue;
                            ll tasu=change[j+l];
                            chmin(dpdp[j+1][state[(bit+(1<<l))/2]],dpdp[j][kk]+c[l]+tasu);
                        }
                    }
                }
            }
            
            for(int b=0;b<bi;b++) dp[t+1][b]=dpdp[D][b];
        }
    }
}