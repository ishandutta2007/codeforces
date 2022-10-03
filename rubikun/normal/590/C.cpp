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
const int mod=998244353,MAX=1005,INF=1<<28;
int dis[3][MAX][MAX];
vector<int> dh={0,1,0,-1},dw={1,0,-1,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    for(int t=0;t<3;t++){
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) dis[t][i][j]=INF;
        deque<pair<int,int>> Q;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]==char('1'+t)){
                    dis[t][i][j]=0;
                    Q.push_back(mp(i,j));
                }
            }
        }
        while(!Q.empty()){
            auto u=Q.front();Q.pop_front();
            for(int k=0;k<4;k++){
                int toh=u.fi+dh[k],tow=u.se+dw[k];
                if(toh<0||toh>=H||tow<0||tow>=W) continue;
                if(S[toh][tow]=='#') continue;
                if(S[toh][tow]=='.'){
                    if(chmin(dis[t][toh][tow],dis[t][u.fi][u.se]+1)) Q.push_back(mp(toh,tow));
                }else{
                    if(chmin(dis[t][toh][tow],dis[t][u.fi][u.se])) Q.push_front(mp(toh,tow));
                }
            }
        }
    }
    
    int ans=INF;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#') continue;
            if(S[i][j]=='.'){
                int sum=0;
                for(int t=0;t<3;t++) sum+=dis[t][i][j];
                chmin(ans,sum-2);
            }else{
                int sum=0;
                for(int t=0;t<3;t++) sum+=dis[t][i][j];
                if(sum==0) ans=0;
            }
        }
    }
    
    if(ans==INF) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}