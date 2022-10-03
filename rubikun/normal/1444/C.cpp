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
const int mod=998244353,MAX=500005,INF=1<<30;

// from https://ei1333.github.io/luzhiled/snippets/structure/union-find.html

struct UnionFindUndo {
    vector< int > data;
    stack< pair< int, int > > history;
    
    UnionFindUndo(int sz) {
        data.assign(sz, -1);
    }
    
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        history.emplace(x, data[x]);
        history.emplace(y, data[y]);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }
    
    int find(int k) {
        if(data[k] < 0) return (k);
        return (find(data[k]));
    }
    
    int size(int k) {
        return (-data[find(k)]);
    }
    
    void undo() {
        data[history.top().first] = history.top().second;
        history.pop();
        data[history.top().first] = history.top().second;
        history.pop();
    }
    
    void snapshot() {
        while(history.size()) history.pop();
    }
    
    void rollback() {
        while(history.size()) undo();
    }
};

vector<pair<int,int>> G[MAX];
bool ng[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
    }
    
    UnionFindUndo uf(2*N);
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(A[a]==A[b]){
            uf.unite(a,N+b);
            uf.unite(N+a,b);
        }else{
            if(A[a]>A[b]) swap(a,b);
            G[A[a]].push_back(mp(a,b));
        }
    }
    
    for(int i=0;i<N;i++){
        if(uf.find(i)==uf.find(i+N)) ng[A[i]]=1;
    }
    
    ll ans=0;
    for(int i=0;i<K;i++){
        if(!ng[i]) ans++;
    }
    
    ans=ans*(ans-1)/2;
    
    for(int i=0;i<K;i++){
        sort(all(G[i]),[&](auto a,auto b){
            return A[a.se]<A[b.se];
        });
        
        //for(auto a:G[i]) cout<<a.fi<<" "<<a.se<<endl;
        //cout<<endl;
        
        int j=0;
        while(j<si(G[i])){
            int k=j+1;
            while(k<si(G[i])&&A[G[i][j].se]==A[G[i][k].se]) k++;
            int sz=0;
            bool ok=true;
            for(int l=j;l<k;l++){
                uf.unite(G[i][l].fi,N+G[i][l].se);
                uf.unite(N+G[i][l].fi,G[i][l].se);
                sz+=2;
                if(uf.find(G[i][l].fi)==uf.find(N+G[i][l].fi)){
                    ok=false;
                    break;
                }
            }
            
            if(!ok&&!ng[i]&&!ng[A[G[i][j].se]]) ans--;
            
            while(sz--) uf.undo();
            
            //cout<<j<<" "<<k<<endl;
            
            j=k;
        }
    }
    
    cout<<ans<<endl;
    
    
}