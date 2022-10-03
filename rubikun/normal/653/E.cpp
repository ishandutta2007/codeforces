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
const int mod=1000000007,MAX=300005,INF=1<<30;

struct edge{
    int a;
    int b;
};

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
    
    void unite(int b,int a){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int cnte[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    int X=0;
    vector<edge> E(M);
    int rem=N-1;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(a>b) swap(a,b);
        E[i]={a,b};
        if(a==0) rem--;
    }
    
    if(rem<K){
        cout<<"impossible\n";
        return 0;
    }
    
    sort(all(E),[](auto a,auto b){
        return a.b<b.b;
    });
    
    {
        UF uf;uf.init(N);
        
        set<int> alive;
        
        int j=0;
        for(int i=0;i<N;i++){
            vector<int> hiku,kesu;
            while(j<si(E)&&E[j].b==i){
                cnte[uf.root(E[j].a)]++;
                hiku.push_back(uf.root(E[j].a));
                j++;
            }
            
            for(int r:alive){
                if(cnte[r]<uf.size[r]){
                    kesu.push_back(r);
                    uf.unite(r,i);
                }
            }
            
            for(int a:hiku) cnte[a]=0;
            
            for(int a:kesu){
                alive.erase(a);
            }
            alive.insert(i);
            
            //cout<<i<<" ";
            //for(int a:alive) cout<<a<<" ";
            //cout<<endl;
        }
        
        if(si(alive)>1){
            cout<<"impossible\n";
            return 0;
        }
        
    }
    
    {
        UF uf;uf.init(N);
        
        set<int> alive;
        
        int j=0;
        for(int i=1;i<N;i++){
            vector<int> hiku,kesu;
            while(j<si(E)&&E[j].b==i){
                if(E[j].a){
                    cnte[uf.root(E[j].a)]++;
                    hiku.push_back(uf.root(E[j].a));
                }
                j++;
            }
            
            for(int r:alive){
                if(cnte[r]<uf.size[r]){
                    kesu.push_back(r);
                    uf.unite(r,i);
                }
            }
            
            for(int a:hiku) cnte[a]=0;
            
            for(int a:kesu){
                alive.erase(a);
            }
            alive.insert(i);
            
            //cout<<i<<" ";
            //for(int a:alive) cout<<a<<" ";
            //cout<<endl;
        }
        
        if(si(alive)<=K){
            cout<<"possible\n";
        }else{
            cout<<"impossible\n";
        }
        
    }

}