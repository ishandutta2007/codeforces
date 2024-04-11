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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        map<ll,ll> L,R;
        map<pair<ll,ll>,ll> MA;
        ll l=INF,r=-INF;
        for(int i=0;i<N;i++){
            ll a,b,c;cin>>a>>b>>c;
            if(L.count(a)) chmin(L[a],c);
            else L[a]=c;
            if(R.count(b)) chmin(R[b],c);
            else R[b]=c;
            if(MA.count(mp(a,b))) chmin(MA[mp(a,b)],c);
            else MA[mp(a,b)]=c;
            chmin(l,a);
            chmax(r,b);
            ll ans=1LL<<60;
            chmin(ans,L[l]+R[r]);
            if(MA.count(mp(l,r))) chmin(ans,MA[mp(l,r)]);
            cout<<ans<<"\n";
        }
    }
}