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
const int mod=1000000007,MAX=1005,INF=1<<30;

int H,W;
ll when[MAX][MAX];
char T[MAX][MAX];

vector<int> dh={0,1,0,-1},dw={1,0,-1,0};

void BFS(vector<pair<int,int>> &s){
    queue<pair<int,int>> Q;
    for(auto a:s){
        when[a.fi][a.se]=0;
        Q.push(a);
    }
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        int h=u.fi,w=u.se;
        
        for(int k=0;k<4;k++){
            int toh=h+dh[k],tow=w+dw[k];
            if(toh<0||toh>=H||tow<0||tow>=W) continue;
            if(when[toh][tow]!=INF) continue;
            
            when[toh][tow]=when[h][w]+1;
            Q.push({toh,tow});
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>H>>W;
    int Q;cin>>Q;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>T[i][j];
            when[i][j]=INF;
        }
    }
    
    vector<pair<int,int>> s;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            bool ok=false;
            for(int k=0;k<4;k++){
                int toh=i+dh[k],tow=j+dw[k];
                if(toh<0||toh>=H||tow<0||tow>=W) continue;
                
                if(T[i][j]==T[toh][tow]) ok=true;
            }
            if(ok) s.push_back(mp(i,j));
        }
    }
    
    BFS(s);
    
    for(int i=0;i<Q;i++){
        int h,w;
        ll t;cin>>h>>w>>t;
        h--;w--;
        
        if(when[h][w]==INF||when[h][w]>=t) cout<<T[h][w]<<"\n";
        else{
            int a=int(T[h][w]-'0');
            if((t-when[h][w])%2) a^=1;
            
            cout<<a<<"\n";
        }
    }
}