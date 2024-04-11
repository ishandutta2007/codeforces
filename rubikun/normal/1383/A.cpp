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
        string A,B;cin>>A>>B;
        UF uf;
        uf.init(20);
        bool ok=true;
        
        for(int i=0;i<N;i++){
            if(A[i]>B[i]) ok=false;
            else if(A[i]!=B[i]){
                uf.unite(int(A[i]-'a'),int(B[i]-'a'));
            }
        }
        
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        
        set<int> SE;
        for(int i=0;i<20;i++) SE.insert(uf.root(i));
        
        int res=0;
        
        for(int a:SE) res+=uf.size[a]-1;
        
        cout<<res<<"\n";
    }
}