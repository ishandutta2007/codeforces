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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

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
    
    int N;cin>>N;
    UF uf;uf.init(N);
    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];P[i]--;
        uf.unite(i,P[i]);
    }
    vector<vector<int>> S;
    for(int i=0;i<N;i++){
        if(uf.root(i)!=i) continue;
        int now=i;
        vector<int> A;
        while(1){
            A.push_back(now);
            now=P[now];
            if(now==i) break;
        }
        S.push_back(A);
    }
    
    sort(all(S),[](auto a,auto b){
        return si(a)<si(b);
    });
    
    if(si(S[0])==1){
        cout<<"YES\n";
        int u=S[0][0];
        for(int i=0;i<N;i++){
            if(i==u) continue;
            cout<<u+1<<" "<<i+1<<"\n";
        }
    }else if(si(S[0])==2){
        for(auto a:S){
            if(si(a)&1){
                cout<<"NO\n";
                return 0;
            }
        }
        cout<<"YES\n";
        int u=S[0][0],v=S[0][1];
        cout<<u+1<<" "<<v+1<<"\n";
        for(auto a:S){
            if(a==S[0]) continue;
            for(int i=0;i<si(a);i++){
                if(i&1) cout<<a[i]+1<<" "<<v+1<<"\n";
                else cout<<a[i]+1<<" "<<u+1<<"\n";
            }
        }
    }else{
        cout<<"NO\n";
    }
    
}