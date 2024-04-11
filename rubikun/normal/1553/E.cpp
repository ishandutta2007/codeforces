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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<int> p(N),needcnt(N);
        for(int i=0;i<N;i++){
            cin>>p[i];p[i]--;
            int need=i-p[i];
            if(need<0) need+=N;
            needcnt[need]++;
        }
        
        vector<int> ans;
        
        for(int i=0;i<N;i++){
            if(needcnt[i]<N/3) continue;
            UF uf;uf.init(N);
            vector<int> B(N);
            for(int j=0;j<N;j++){
                B[j]=j-i;
                if(B[j]<0) B[j]+=N;
                uf.unite(p[j],B[j]);
                //cout<<B[j]<<" ";
            }
            //cout<<endl;
            int sum=0;
            for(int j=0;j<N;j++){
                if(uf.root(j)==j) sum+=uf.size[j]-1;
            }
            
            if(sum<=M) ans.push_back(i);
        }
        
        cout<<si(ans);
        for(int a:ans) cout<<" "<<a;
        cout<<"\n";
    }
}