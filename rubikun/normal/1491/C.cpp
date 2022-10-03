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
    vector<int> par,size,ma;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        ma.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
            ma[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            chmax(ma[root(a)],ma[root(b)]);
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
        //N=5000;
        UF uf;
        uf.init(N+1);
        vector<ll> A(N);
        ll ans=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            //A[i]=1000000000;
            if(A[i]>N*N){
                ans+=A[i]-N*N;
                A[i]=N*N;
            }
        }
        
        bool ok=true;
        for(int i=0;i<N;i++) if(A[i]>1) ok=false;
        
        if(ok){
            cout<<ans<<"\n";
            continue;
        }
        
        int s=0;
        while(s<N){
            ans++;
            int now=s;
            while(now<N){
                ll x=A[now];
                if(x==1){
                    if(uf.ma[uf.root(now)]==now){
                        uf.unite(now,now+1);
                        now++;
                    }else{
                        now=uf.ma[uf.root(now)];
                    }
                }else{
                    A[now]--;
                    if(A[now]>max((now-s)*N,N)){
                        ans+=A[now]-max((now-s)*N,N);
                        A[now]=max((now-s)*N,N);
                    }
                    now+=x;
                }
            }
            while(s<N&&A[s]==1) s++;
        }
        
        cout<<ans<<endl;
    }
}