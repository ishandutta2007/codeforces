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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> S(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        S[i]=mp(a,b);
    }
    
    int ans=0;
    
    for(int i=0;i+1<M;i++){
        int diff=S[i+1].fi-S[i].fi,h=abs(S[i+1].se-S[i].se);
        int a=min(S[i].se,S[i+1].se),b=max(S[i].se,S[i+1].se);
        if(h>diff) ans=INF;
        else chmax(ans,b+(diff-h)/2);
    }
    
    chmax(ans,S[0].se+(S[0].fi-1));
    chmax(ans,S[M-1].se+(N-S[M-1].fi));
    
    if(ans==INF) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
}