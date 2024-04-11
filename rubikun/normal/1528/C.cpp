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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

vector<int> G1[MAX],G2[MAX];
int timer=0,ans=0;
int fii[MAX],la[MAX];

void pre(int u){
    fii[u]=timer;
    timer++;
    
    for(int to:G2[u]){
        pre(to);
    }
    
    la[u]=timer;
    timer++;
}

set<pair<int,int>> SE;

void DFS(int u){
    int v=-1;
    auto it=SE.lower_bound(mp(fii[u],u));
    
    if(it!=SE.begin()){
        it--;
        v=(*it).se;
        if(la[v]>=fii[u]){
            SE.erase(it);
        }
    }
    SE.insert(mp(fii[u],u));
    
    chmax(ans,si(SE));
    
    for(int to:G1[u]){
        DFS(to);
    }
    
    SE.erase(mp(fii[u],u));
    
    if(v!=-1){
        SE.insert(mp(fii[v],v));
    }
    
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G1[i].clear();
            G2[i].clear();
            fii[i]=la[i]=0;
        }
        timer=0;
        ans=0;
        SE.clear();
        
        for(int i=1;i<N;i++){
            int p;cin>>p;p--;
            G1[p].push_back(i);
        }
        for(int i=1;i<N;i++){
            int p;cin>>p;p--;
            G2[p].push_back(i);
        }
        
        pre(0);
        DFS(0);
        
        cout<<ans<<"\n";
    }
}