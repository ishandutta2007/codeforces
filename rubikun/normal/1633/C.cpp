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
const int mod=998244353,MAX=300005,INF=1<<29;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll hc,dc,hm,dm;cin>>hc>>dc>>hm>>dm;
        ll K,w,a;cin>>K>>w>>a;
        bool f=false;
        for(ll i=0;i<=K;i++){
            ll j=K-i;
            ll hcn=hc+i*a,dcn=dc+j*w;
            ll need1=(hm+dcn-1)/dcn;
            ll need2=(hcn+dm-1)/dm;
            if(need1<=need2) f=true;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}