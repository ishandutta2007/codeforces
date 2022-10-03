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
const int mod=1000000007,MAX=500005,INF=1<<30;

//from:https://ei1333.github.io/luzhiled/snippets/structure/union-find.html

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

struct edge{
    int from;
    int to;
    int cost;
    int id;
};

vector<edge> G[MAX];
bool can[MAX],ans[MAX];
int lim[MAX],cntc[MAX];
vector<vector<pair<edge,int>>> query[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    UnionFindUndo uf(N);
    
    vector<edge> E(M);
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[c].push_back({a,b,c,i});
        E[i]={a,b,c,i};
        can[i]=true;
    }
    
    int Q;cin>>Q;
    
    for(int q=0;q<Q;q++){
        int k;cin>>k;
        vector<int> use(k);
        for(int i=0;i<k;i++){
            cin>>use[i];
            use[i]--;
        }
        sort(all(use),[&](int a,int b){
            return E[a].cost<E[b].cost;
        });
        
        for(int i=0;i<k;i++){
            auto e=E[use[i]];
            if(si(query[e.cost])==0||query[e.cost].back().back().se!=q) query[e.cost].push_back({});
            query[e.cost].back().push_back(mp(e,q));
        }
        
        ans[q]=true;
    }
    
    for(int c=1;c<=500000;c++){
        for(auto x:query[c]){
            for(auto e:x){
                if(!(uf.unite(e.fi.from,e.fi.to))) ans[e.se]=false;
            }
            
            for(int t=0;t<si(x);t++) uf.undo();
        }
        
        for(auto e:G[c]) uf.unite(e.from,e.to);
    }
    
    for(int q=0;q<Q;q++){
        if(ans[q]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}