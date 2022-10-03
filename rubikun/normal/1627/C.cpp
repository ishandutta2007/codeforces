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
const int mod=998244353,MAX=100005,INF=1<<30;
vector<pair<int,int>> G[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
        }
        
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;a--;b--;
            G[a].push_back(mp(b,i));
            G[b].push_back(mp(a,i));
        }
        bool ok=true;
        for(int i=0;i<N;i++) ok&=(si(G[i])<=2);
        
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }
        
        int r=-1;
        for(int i=0;i<N;i++){
            if(si(G[i])==1){
                r=i;
                break;
            }
        }
        vector<int> ans(N-1);
        vector<int> mita(N);
        
        mita[r]=true;
        for(int q=0;q<N-1;q++){
            for(auto to:G[r]){
                if(mita[to.fi]) continue;
                mita[to.fi]=true;
                ans[to.se]=2+(q&1);
                r=to.fi;
                break;
            }
        }
        
        for(int i=0;i<N-1;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}