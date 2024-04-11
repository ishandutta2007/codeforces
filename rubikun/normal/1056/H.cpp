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
const int mod=1000000007,MAX=300005,INF=1<<30;

int where[MAX];
pair<int,int> T[120000005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(where,-1,sizeof(where));
    
    int QQ;cin>>QQ;
    while(QQ--){
        int N,Q;cin>>N>>Q;
        vector<vector<int>> S(Q);
        vector<int> small,big;
        
        int D=pow(N,0.6);
        
        for(int i=0;i<Q;i++){
            int k;cin>>k;
            S[i].resize(k);
            for(int j=0;j<k;j++){
                cin>>S[i][j];
                S[i][j]--;
            }
            if(k<=D) small.push_back(i);
            else big.push_back(i);
        }
        
        bool ok=true;
        
        vector<int> sz(N+1),sz2;
        
        for(int i=0;i<si(small);i++){
            for(int j=0;j<si(S[small[i]]);j++){
                sz[S[small[i]][j]+1]+=si(S[small[i]])-j-1;
            }
        }
        
        for(int i=1;i<=N;i++) sz[i]+=sz[i-1];
        
        int m=N,hiku=sz[N-1];
        for(int i=1;i<=N;i++){
            if(sz[i]>sz[N]/2){
                m=i-1;
                hiku=sz[i-1];
                break;
            }
        }
        
        sz2=sz;
        
        for(int i=0;i<si(small);i++){
            for(int j=0;j<si(S[small[i]]);j++){
                if(S[small[i]][j]>=m) continue;
                for(int k=j+1;k<si(S[small[i]]);k++){
                    if(S[small[i]][j]<m){
                        T[sz2[S[small[i]][j]]]=mp(S[small[i]][k],S[small[i]][j+1]);
                        sz2[S[small[i]][j]]++;
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=sz[i];j<sz[i+1];j++){
                if(where[T[j].fi]!=-1){
                    ok&=(where[T[j].fi]==T[j].se);
                }
                where[T[j].fi]=T[j].se;
            }
            
            for(int j=sz[i];j<sz[i+1];j++){
                where[T[j].fi]=-1;
            }
        }
        
        for(int i=0;i<si(small);i++){
            for(int j=0;j<si(S[small[i]]);j++){
                if(S[small[i]][j]<m) continue;
                for(int k=j+1;k<si(S[small[i]]);k++){
                    if(S[small[i]][j]>=m){
                        T[sz2[S[small[i]][j]]-hiku]=mp(S[small[i]][k],S[small[i]][j+1]);
                        sz2[S[small[i]][j]]++;
                    }
                }
            }
        }
        
        for(int i=m;i<N;i++){
            for(int j=sz[i]-hiku;j<sz[i+1]-hiku;j++){
                if(where[T[j].fi]!=-1){
                    ok&=(where[T[j].fi]==T[j].se);
                }
                where[T[j].fi]=T[j].se;
            }
            
            for(int j=sz[i]-hiku;j<sz[i+1]-hiku;j++){
                where[T[j].fi]=-1;
            }
        }
        
        for(int i=0;i<si(big);i++){
            for(int j=0;j<Q;j++){
                for(int k=0;k<si(S[j]);k++){
                    where[S[j][k]]=k;
                }
                
                int ma=-1;
                
                for(int k=si(S[big[i]])-1;k>=0;k--){
                    int x=where[S[big[i]][k]];
                    if(x==-1) continue;
                    if(x<ma){
                        ok&=(S[big[i]][k+1]==S[j][x+1]);
                    }
                    chmax(ma,x);
                }
                
                for(int k=0;k<si(S[j]);k++){
                    where[S[j][k]]=-1;
                }
            }
        }
        
        if(ok) cout<<"Robot"<<"\n";
        else cout<<"Human"<<"\n";
    }
}