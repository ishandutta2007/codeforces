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
    
    vector<ll> fac;
    fac.push_back(1);
    int t=2;
    while(fac.back()<=1000000000000LL){
        fac.push_back(fac.back()*t);
        t++;
    }
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        int ans=INF;
        for(int bit=0;bit<(1<<si(fac));bit++){
            ll rem=N;
            for(int i=0;i<si(fac);i++){
                if(bit&(1<<i)) rem-=fac[i];
            }
            if(rem<0) continue;
            int need=__builtin_popcount(bit)+__builtin_popcountll(rem);
            chmin(ans,need);
        }
        if(ans==INF) ans=-1;
        cout<<ans<<"\n";
    }
}