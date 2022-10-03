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
    
    int h,m,s,t1,t2;cin>>h>>m>>s>>t1>>t2;
    h%=12;
    t1%=12;
    t2%=12;
    
    UF uf;uf.init(12);
    
    vector<int> ok(12,1);
    if(m==0&&s==0){
        ok[(h+11)%12]=0;
        ok[h]=0;
    }else{
        ok[h]=0;
    }
    
    if(m%5==0&&s==0){
        ok[(m/5+11)%12]=0;
        ok[(m/5)]=0;
    }else{
        ok[m/5]=0;
    }
    
    if(s%5==0){
        ok[(s/5+11)%12]=0;
        ok[(s/5)]=0;
    }else{
        ok[s/5]=0;
    }
    
    for(int i=0;i<12;i++){
        if(ok[i]) uf.unite(i,(i+1)%12);
    }
    
    if(uf.check(t1,t2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
    
}