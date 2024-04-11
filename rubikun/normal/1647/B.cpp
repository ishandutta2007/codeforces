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
const int mod=998244353,MAX=300005,INF=1<<30;

//Union Find


struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        for(int i=0;i<H;i++) cin>>S[i];
        UF uf;uf.init(H*W);
        vector<vector<int>> rui(H+1,vector<int>(W+1));
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]=='1'){
                    if(j+1<W&&S[i][j+1]=='1') uf.unite(i*W+j,i*W+j+1);
                    if(i+1<H&&S[i+1][j]=='1') uf.unite(i*W+j,(i+1)*W+j);
                }
                rui[i+1][j+1]=(int)(S[i][j]-'0');
            }
        }
        for(int i=1;i<=H;i++) for(int j=0;j<=W;j++) rui[i][j]+=rui[i-1][j];
        for(int j=1;j<=W;j++) for(int i=0;i<=H;i++) rui[i][j]+=rui[i][j-1];
        
        bool f=true;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(S[i][j]=='1'){
                    if(i==0||S[i-1][j]=='0'){
                        if(j==0||S[i][j-1]=='0'){
                            int x=i;
                            while(x<H&&S[x][j]=='1') x++;
                            int y=j;
                            while(y<W&&S[i][y]=='1') y++;
                            int z=rui[x][y]+rui[i][j]-rui[x][j]-rui[i][y];
                            if(z==uf.size[uf.root(i*W+j)]&&z==(x-i)*(y-j)) continue;
                            else f=false;
                        }
                    }
                }
            }
        }
        
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}