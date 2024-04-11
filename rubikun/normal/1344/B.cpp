#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=1005,INF=1<<30;
bool check[MAX][MAX];
bool exi[MAX][2],put[MAX][2];

vector<int> x[MAX],y[MAX];

int par[MAX*MAX],siz[MAX*MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        siz[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        siz[root(a)]+=siz[root(b)];
        par[root(b)]=root(a);
    }
}

vector<int> dh={0,-1,0,1},dw={1,0,-1,0};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    
    for(int i=0;i<H;i++){
        cin>>S[i];
        for(int j=0;j<W;j++){
            if(S[i][j]=='#'){
                exi[i][0]=1;
                exi[j][1]=1;
            }
        }
    }
    
    int ans=0;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(exi[i][0]==0&&exi[j][1]==0){
                check[i][j]=1;
                x[i].push_back(j);
                y[j].push_back(i);
                put[i][0]=1;
                put[j][1]=1;
            }
        }
    }
    
    for(int i=0;i<H;i++){
        if(exi[i][0]==0&&put[i][0]==0) ans=-INF;
    }
    
    for(int j=0;j<W;j++){
        if(exi[j][1]==0&&put[j][1]==0) ans=-INF;
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#'){
                check[i][j]=1;
                x[i].push_back(j);
                y[j].push_back(i);
            }
        }
    }
    
    for(int i=0;i<H;i++){
        x[i].push_back(-1);
        x[i].push_back(W);
        sort(all(x[i]));
    }
    
    for(int j=0;j<W;j++){
        y[j].push_back(-1);
        y[j].push_back(H);
        sort(all(y[j]));
    }
    
    init(H*W);
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<4;k++){
                if(i+dh[k]<0||i+dh[k]>=H||j+dw[k]<0||j+dw[k]>=W) continue;
                if(S[i][j]=='#'&&S[i+dh[k]][j+dw[k]]=='#') unite(i*W+j,(i+dh[k])*W+j+dw[k]);
            }
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#'){
                int a=*lower_bound(all(x[i]),j+1);
                if(a!=W&&a!=j+1) ans=-INF;
                
                auto it=lower_bound(all(x[i]),j);
                it--;
                a=*it;
                if(a!=-1&&a!=j-1) ans=-INF;
                
                a=*lower_bound(all(y[j]),i+1);
                if(a!=H&&a!=i+1) ans=-INF;
                
                it=lower_bound(all(y[j]),i);
                it--;
                a=*it;
                if(a!=-1&&a!=i-1) ans=-INF;
            }
        }
    }
    
    if(ans==-INF){
        cout<<-1<<endl;
        return 0;
    }
    
    set<int> SE;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#') SE.insert(root(i*W+j));
        }
    }
    
    cout<<si(SE)<<"\n";
}