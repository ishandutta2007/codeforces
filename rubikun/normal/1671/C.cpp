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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,X;cin>>N>>X;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        A.push_back(INF);
        ll ans=0,sum=0;
        vector<pair<ll,ll>> S;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(X<sum) continue;
            ll r=(X-sum)/(i+1);
            if(si(S)&&S.back().fi==r) S.back().se=i+1;
            else S.push_back(mp(r,i+1));
        }
        S.push_back(mp(-1,-1));
        
        for(int i=0;i+1<si(S);i++){
            ans+=S[i].se*(S[i+1].fi-S[i].fi);
        }
        
        ans*=-1;
        cout<<ans<<"\n";
    }
}