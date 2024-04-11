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
const int mod1=1000000007,mod2=1000000009,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M;cin>>N>>M;
    vector<pair<ll,ll>> S(N),T(M);
    vector<ll> ans(N),diff(N),base(N),diffsum(N+1);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>S[i].fi>>S[i].se;
        base[i]=S[i].fi;
        diff[i]=S[i].se-S[i].fi;
        sum+=base[i];
    }
    sort(all(diff));
    for(int i=0;i<M;i++){
        cin>>T[i].fi>>T[i].se;
        T[i].fi--;
        T[i].se--;
    }
    
    for(int i=1;i<=N;i++) diffsum[i]=diffsum[i-1]+diff[i-1];
    
    for(int i=0;i<N;i++){
        ans[i]=sum-base[i]+base[i]*(N-1);
        
        auto it=lower_bound(all(diff),S[i].se-S[i].fi);
        int d=it-diff.begin();
        ans[i]+=diffsum[d];
        ans[i]+=(S[i].se-S[i].fi)*(N-1-d);
    }
    
    for(int i=0;i<M;i++){
        int a=T[i].fi,b=T[i].se;
        ll x=S[a].fi+S[b].se;
        ll y=S[b].fi+S[a].se;
        ans[a]-=min(x,y);
        ans[b]-=min(x,y);
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}