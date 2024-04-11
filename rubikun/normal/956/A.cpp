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
const int mod=1000000007,MAX=200005,INF=1<<30;

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
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
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    int cnt=0;
    for(int i=0;i<H;i++){
        cin>>S[i];
        for(int j=0;j<W;j++) if(S[i][j]=='#') cnt++;
    }
    
    UF uf1,uf2;
    uf1.init(H);
    uf2.init(W);
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=j+1;k<W;k++){
                if(S[i][j]=='#'&&S[i][k]=='#') uf2.unite(j,k);
            }
        }
    }
    
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            for(int k=i+1;k<H;k++){
                if(S[i][j]=='#'&&S[k][j]=='#') uf1.unite(i,k);
            }
        }
    }
    
    set<pair<int,int>> ro;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#'){
                int a=uf1.root(i),b=uf2.root(j);
                ro.insert(mp(a,b));
            }
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int a=uf1.root(i),b=uf2.root(j);
            if(ro.count(mp(a,b))){
                if(S[i][j]=='.'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    
    cout<<"Yes"<<endl;
}