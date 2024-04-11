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
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<int> G[MAX];
int N,M,K;
int siz[MAX];
set<pair<int,int>> deg;

void solve(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        G[i].clear();
        siz[i]=0;
    }
    deg.clear();
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        siz[a]++;
        siz[b]++;
    }
    
    if(K==1){
        cout<<2<<"\n";
        cout<<1<<"\n";
        return;
    }
    
    for(int i=0;i<N;i++){
        deg.insert(mp(siz[i],i));
        sort(all(G[i]));
    }
    
    while(si(deg)){
        auto a=*deg.begin();
        
        if(a.fi>=K){
            cout<<1<<" "<<si(deg)<<"\n";
            for(auto x:deg){
                cout<<x.se+1<<" ";
            }
            cout<<"\n";
            return;
        }else{
            deg.erase(a);
            
            for(auto to:G[a.se]){
                if(deg.count(mp(siz[to],to))){
                    deg.erase(mp(siz[to],to));
                    siz[to]--;
                    deg.insert(mp(siz[to],to));
                }
            }
        }
        
        if(si(deg)<=K){
            deg.clear();
            break;
        }
    }
    
    for(int i=0;i<N;i++){
        siz[i]=si(G[i]);
        deg.insert(mp(siz[i],i));
    }
    
    if(ll(K)*ll(K-1)/2>M){
        cout<<-1<<"\n";
        return;
    }
    
    while(si(deg)){
        auto a=*deg.begin();
        
        if(a.fi==K-1){
            vector<int> clique;
            //clique.push_back(a.se);
            for(auto to:G[a.se]){
                if(deg.count(mp(siz[to],to))){
                    clique.push_back(to);
                }
            }
            
            bool check=true;
            
            for(int i=0;i<si(clique);i++){
                for(int j=i+1;j<si(clique);j++){
                    int u=clique[i],v=clique[j];
                    if(!binary_search(all(G[u]),v)) check=false;
                    if(!check) break;
                }
                if(!check) break;
            }
            
            if(check){
                cout<<2<<"\n";
                cout<<a.se+1<<" ";
                for(int x:clique) cout<<x+1<<" ";
                cout<<"\n";
                return;
            }else{
                deg.erase(a);
                
                for(auto to:clique){
                    deg.erase(mp(siz[to],to));
                    siz[to]--;
                    deg.insert(mp(siz[to],to));
                }
            }
        }else{
            deg.erase(a);
            
            for(auto to:G[a.se]){
                if(deg.count(mp(siz[to],to))){
                    deg.erase(mp(siz[to],to));
                    siz[to]--;
                    deg.insert(mp(siz[to],to));
                }
            }
        }
    }
    
    cout<<-1<<"\n";
    return;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        solve();
    }
}