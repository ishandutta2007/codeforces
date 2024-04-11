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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

vector<int> dh={0,1,0,-1},dw={1,0,-1,0};
ll dis[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    
    auto f=[&](int h,int w){
        return h*W+w;
    };
    
    auto g=[&](int id){
        return mp(id/W,id%W);
    };
    
    ll P,Q;cin>>P>>Q;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    
    for(int i=0;i<MAX;i++) dis[i]=INF;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='.'){
                dis[f(i,j)]=0;
                PQ.push(mp(0LL,f(i,j)));
            }
        }
    }
    
    while(!PQ.empty()){
        auto [d,id]=PQ.top();PQ.pop();
        if(dis[id]<d) continue;
        auto [h,w]=g(id);
        
        for(int k=0;k<4;k++){
            int toh=h+dh[k],tow=w+dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(S[toh][tow]=='#') continue;
            toh+=dh[k];
            tow+=dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(S[toh][tow]=='#') continue;
            int h1=h+dh[k],w1=w+dw[k];
            int h2=h1+dh[k],w2=w1+dw[k];
            if(k==0){
                if(S[h1][w1]=='L'&&S[h2][w2]=='R'){
                    
                }else{
                    continue;
                }
            }
            if(k==1){
                if(S[h1][w1]=='U'&&S[h2][w2]=='D'){
                    
                }else{
                    continue;
                }
            }
            if(k==2){
                if(S[h1][w1]=='R'&&S[h2][w2]=='L'){
                    
                }else{
                    continue;
                }
            }
            if(k==3){
                if(S[h1][w1]=='D'&&S[h2][w2]=='U'){
                    
                }else{
                    continue;
                }
            }
            if(chmin(dis[f(toh,tow)],d+Q)){
                PQ.push(mp(d+Q,f(toh,tow)));
            }
        }
        
        for(int k=0;k<4;k++){
            int toh=h+dh[k],tow=w+dw[k];
            toh+=dh[(k+1)%4];
            tow+=dw[(k+1)%4];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(S[toh][tow]=='#') continue;
            int h1=h+dh[k],w1=w+dw[k];
            int h2=h+dh[(k+1)%4],w2=w+dw[(k+1)%4];
            if(S[h1][w1]=='#'&&S[h2][w2]=='#') continue;
            
            bool ok=false;
            
            if(k==0){
                if(S[h1][w1]=='U'&&S[toh][tow]=='D'){
                    ok=true;
                }
                if(S[h2][w2]=='L'&&S[toh][tow]=='R'){
                    ok=true;
                }
            }
            if(k==1){
                if(S[h1][w1]=='R'&&S[toh][tow]=='L'){
                    ok=true;
                }
                if(S[h2][w2]=='U'&&S[toh][tow]=='D'){
                    ok=true;
                }
            }
            if(k==2){
                if(S[h1][w1]=='D'&&S[toh][tow]=='U'){
                    ok=true;
                }
                if(S[h2][w2]=='R'&&S[toh][tow]=='L'){
                    ok=true;
                }
            }
            if(k==3){
                if(S[h1][w1]=='L'&&S[toh][tow]=='R'){
                    ok=true;
                }
                if(S[h2][w2]=='D'&&S[toh][tow]=='U'){
                    ok=true;
                }
            }
            
            if(!ok) continue;
            
            if(chmin(dis[f(toh,tow)],d+P)){
                PQ.push(mp(d+P,f(toh,tow)));
            }
        }
    }
    
    ll ans=INF;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#') continue;
            if(i+1<H){
                if(S[i+1][j]!='#'){
                    chmin(ans,dis[f(i,j)]+dis[f(i+1,j)]);
                }
            }
            if(j+1<W){
                if(S[i][j+1]!='#'){
                    chmin(ans,dis[f(i,j)]+dis[f(i,j+1)]);
                }
            }
        }
    }
    
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}