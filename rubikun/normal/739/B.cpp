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

vector<pair<int,int>> G[MAX];
int ans[MAX];
int A[MAX];
multiset<ll> S[MAX];
ll ad[MAX];

void solve(int u){
    S[u].insert(A[u]);
    for(auto to:G[u]){
        solve(to.fi);
        auto it=S[to.fi].begin();
        while(it!=S[to.fi].end()){
            if((*it)+ad[to.fi]-to.se<0) it=S[to.fi].erase(it);
            else break;
        }
        if(si(S[u])<si(S[to.fi])){
            ll a=ad[u],b=ad[to.fi],c=to.se;
            ad[u]=b-c;
            swap(S[u],S[to.fi]);
            for(ll x:S[to.fi]){
                S[u].insert(x+a-(b-c));
            }
        }else{
            for(ll x:S[to.fi]){
                S[u].insert(x-to.se+ad[to.fi]-ad[u]);
            }
        }
    }
    ans[u]=si(S[u])-1;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    for(int i=1;i<N;i++){
        int p,x;cin>>p>>x;p--;
        G[p].push_back(mp(i,x));
    }
    
    solve(0);
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}