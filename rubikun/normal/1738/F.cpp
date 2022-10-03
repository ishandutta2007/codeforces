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
const int mod=998244353,MAX=100005,INF=1<<30;

//Union Find


struct UF{
    int n;
    vector<int> par,size,edge,sum,ok;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        sum.assign(n,0);
        ok.assign(n,0);
        
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
            sum[root(a)]+=sum[root(b)];
            ok[root(a)]|=ok[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> d(N);
        for(int i=0;i<N;i++) cin>>d[i];
        
        UF uf;uf.init(N);
        int cn=0;
        while(cn<N){
            pair<int,int> ma=mp(-1,-1);
            for(int i=0;i<N;i++){
                if(!uf.ok[uf.root(i)]) chmax(ma,mp(d[i],i));
            }
            if(ma.fi==-1) break;
            
            int u=ma.se;
            for(int t=0;t<d[u];t++){
                cout<<"? "<<u+1<<endl;
                int x;cin>>x;x--;
                uf.unite(u,x);
                if(uf.ok[uf.root(u)]) break;
            }
            
            uf.ok[uf.root(u)]=true;
        }
        
        cout<<"!";
        for(int i=0;i<N;i++) cout<<" "<<uf.root(i)+1;
        cout<<endl;
    }
}