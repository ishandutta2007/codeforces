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
const int mod=1000000007,MAX=2005,INF=1<<30;
int dis[MAX][MAX];
int H,W;
vector<int> dh={0,1,0,-1},dw={1,0,-1,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>H>>W;
    int sh,sw;cin>>sh>>sw;
    sh--;sw--;
    
    queue<pair<int,int>> Q;
    Q.push(mp(sh,sw));
    
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) dis[i][j]=INF;
    dis[sh][sw]=0;
    
    int liml,limr;cin>>liml>>limr;
    
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        for(int k=0;k<4;k++){
            int toh=u.fi+dh[k],tow=u.se+dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(S[toh][tow]=='*') continue;
            
            if(k==2){
                if(chmin(dis[toh][tow],dis[u.fi][u.se]+1)) Q.push(mp(toh,tow));
            }else{
                if(chmin(dis[toh][tow],dis[u.fi][u.se])) Q.push(mp(toh,tow));
            }
        }
    }
    
    int ans=0;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(dis[i][j]==INF) continue;
            
            int needl=dis[i][j],needr=needl+j-sw;
            chmax(needr,0);
            
            if(needl<=liml&&needr<=limr) ans++;
        }
    }
    
    cout<<ans<<endl;
}