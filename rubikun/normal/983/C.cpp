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
const int mod=1000000007,MAX=2005,M=715,INF=1<<30;

vector<vector<int>> cnt(M,vector<int>(10));
int dis[MAX][M][10];
int revMA[M][4],toplus[M][10],tominus[M][10];
pair<int,int> S[MAX];
int N;
map<vector<int>,int> MA;

struct dat{
    int id;
    int state;
    int floor;
};

void BFS(){
    queue<dat> Q;
    Q.push(dat{0,0,1});
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        int d=dis[u.id][u.state][u.floor];
        
        if(u.floor!=1){
            if(chmin(dis[u.id][u.state][u.floor-1],d+1)){
                Q.push(dat{u.id,u.state,u.floor-1});
            }
        }
        if(u.floor!=9){
            if(chmin(dis[u.id][u.state][u.floor+1],d+1)){
                Q.push(dat{u.id,u.state,u.floor+1});
            }
        }
        
        if(u.id<N){
            if(toplus[u.state][S[u.id].se]!=-1&&S[u.id].fi==u.floor){
                if(chmin(dis[u.id+1][toplus[u.state][S[u.id].se]][u.floor],d+1)){
                    Q.push(dat{u.id+1,toplus[u.state][S[u.id].se],u.floor});
                }
            }
        }
        
        if(tominus[u.state][u.floor]!=-1){
            if(chmin(dis[u.id][tominus[u.state][u.floor]][u.floor],d+1)){
                Q.push(dat{u.id,tominus[u.state][u.floor],u.floor});
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>S[i].fi>>S[i].se;
    
    int id=0;
    
    memset(toplus,-1,sizeof(toplus));
    memset(tominus,-1,sizeof(tominus));
    
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            for(int k=j;k<10;k++){
                for(int l=k;l<10;l++){
                    
                    cnt[id][i]++;
                    cnt[id][j]++;
                    cnt[id][k]++;
                    cnt[id][l]++;
                    
                    MA[cnt[id]]=id;
                    
                    revMA[id][0]=i;
                    revMA[id][1]=j;
                    revMA[id][2]=k;
                    revMA[id][3]=l;
                    
                    id++;
                }
            }
        }
    }
    
    for(int i=0;i<M;i++){
        if(cnt[i][0]==0) continue;
        for(int j=1;j<10;j++){
            cnt[i][j]++;
            cnt[i][0]--;
            //if(MA.count(cnt[i])==0) cout<<"!"<<endl;
            toplus[i][j]=MA[cnt[i]];
            cnt[i][j]--;
            cnt[i][0]++;
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=1;j<10;j++){
            if(cnt[i][j]){
                cnt[i][j]--;
                cnt[i][0]++;
                //if(MA.count(cnt[i])==0) cout<<"!"<<endl;
                tominus[i][j]=MA[cnt[i]];
                cnt[i][j]++;
                cnt[i][0]--;
            }
        }
    }
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<10;k++){
                dis[i][j][k]=INF;
            }
        }
    }
    
    dis[0][0][1]=0;
    
    BFS();
    
    int ans=INF;
    
    for(int j=1;j<=9;j++){
        chmin(ans,dis[N][0][j]);
        //cout<<dis[N][0][j]<<endl;
    }
    
    cout<<ans<<endl;
}