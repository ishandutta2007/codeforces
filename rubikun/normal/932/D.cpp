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
const int mod=1000000007,MAX=400005,INF=1<<30;
ll par[MAX],cost[MAX];
pair<ll,int> mae[MAX][20];//2^j

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<20;j++){
            mae[i][j]=mp(-1,-1);
        }
    }
    mae[0][0]=mp(0,-1);
    
    ll last=0,nex=1;
    
    while(Q--){
        ll k,p,q;cin>>k>>p>>q;
        p^=last;
        q^=last;
        
        p--;
        
        if(k==1){
            par[nex]=p;
            cost[nex]=q;
            
            if(cost[par[nex]]>=cost[nex]){
                mae[nex][0]=mp(cost[nex],par[nex]);
            }else{
                ll left=0,right=nex+3;
                
                while(right-left>1){
                    ll mid=(left+right)/2;
                    ll nowpos=par[nex];
                    bool ok=false;
                    for(int j=0;j<20;j++){
                        if(mid&(1<<j)){
                            nowpos=mae[nowpos][j].se;
                        }
                        if(nowpos<0){
                            ok=true;
                            break;
                        }
                        if(cost[nowpos]>=cost[nex]) ok=true;
                    }
                    
                    if(ok) right=mid;
                    else left=mid;
                }
                
                if(left>nex){
                    mae[nex][0]=mp(cost[nex],-1);
                }else{
                    ll mid=right;
                    ll nowpos=par[nex];
                    for(int j=0;j<20;j++){
                        if(mid&(1<<j)) nowpos=mae[nowpos][j].se;
                    }
                    
                    mae[nex][0]=mp(cost[nex],nowpos);
                }
            }
            
            for(int j=1;j<20;j++){
                if(mae[nex][j-1].se==-1) continue;
                if(mae[mae[nex][j-1].se][j-1].fi<0) continue;
                mae[nex][j]=mp(mae[nex][j-1].fi+mae[mae[nex][j-1].se][j-1].fi,mae[mae[nex][j-1].se][j-1].se);
            }
            
            nex++;
        }else{
            ll left=0,right=nex+2;
            while(right-left>1){
                ll mid=(left+right)/2;
                ll sum=0;
                ll nowpos=p;
                for(int j=0;j<20;j++){
                    if(mid&(1<<j)){
                        if(nowpos<0){
                            sum=1LL<<60;
                            break;
                        }
                        if(mae[nowpos][j].fi<0){
                            sum=1LL<<60;
                            break;
                        }
                        sum+=mae[nowpos][j].fi;
                        nowpos=mae[nowpos][j].se;
                    }
                }
                if(sum>q) right=mid;
                else left=mid;
            }
            
            cout<<left<<"\n";
            
            last=left;
        }
    }
    
    /*for(int i=0;i<nex;i++){
        for(int j=0;j<3;j++){
            cout<<i<<" "<<j<<" "<<mae[i][j].fi<<" "<<mae[i][j].se<<endl;
        }
    }*/
}