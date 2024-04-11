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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> x(N);
        for(int i=0;i<N;i++) cin>>x[i];
        
        priority_queue<pair<int,int>> PQ;
        vector<int> deg(N);
        
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            deg[a]++;
            deg[b]++;
        }
        
        ll ans=0;
        
        for(int i=0;i<N;i++){
            if(deg[i]>=2){
                PQ.push(mp(x[i],i));
            }
            ans+=x[i];
        }
        
        cout<<ans<<" ";
        while(!PQ.empty()){
            auto u=PQ.top();PQ.pop();
            ans+=u.fi;
            cout<<ans<<" ";
            deg[u.se]--;
            if(deg[u.se]>=2){
                PQ.push(mp(x[u.se],u.se));
            }
        }
        cout<<"\n";
    }
    
}