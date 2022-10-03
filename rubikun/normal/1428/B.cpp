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
const int mod=1000000007,MAX=200005;
const int INF=1<<30;
//const ll INF=1LL<<60;

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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        int x=0,y=0;
        for(int i=0;i<N;i++){
            if(S[i]=='>') x++;
            if(S[i]=='<') y++;
        }
        
        if(x==0||y==0){
            cout<<N<<"\n";
            continue;
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++){
            if(S[i]=='-'||S[(i+N-1)%N]=='-') ans++;
        }
        
        cout<<ans<<"\n";
        
        /*UF uf1,uf2;
        uf1.init(N);
        uf2.init(N);
        
        for(int i=0;i<N;i++){
            if(S[i]=='>') uf1.unite(i,(i+1)%N);
            if(S[i]=='<') uf2.unite(i,(i+1)%N);
            if(S[i]=='-'){
                uf1.unite(i,(i+1)%N);
                uf2.unite(i,(i+1)%N);
            }
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++){
            if(S[i]!='<'&&uf2.check(i,(i+1)%N)) ans++;
            else if(S[(i+N-1)%N]!='>'&&uf1.check(i,(i+N-1)%N)) ans++;
        }
        
        cout<<ans<<"\n";*/
    }
}