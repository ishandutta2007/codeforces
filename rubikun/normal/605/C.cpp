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

#define ld long double

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,p,q;cin>>N>>p>>q;
    vector<pair<ll,ll>> P(N);
    ll ma=0;
    for(int i=0;i<N;i++){
        cin>>P[i].fi>>P[i].se;
        chmax(ma,P[i].fi);
    }
    ld l=0,r=1.0/(ld)ma;
    auto f=[&](ld x){
        ld y=INF;
        for(int i=0;i<N;i++){
            chmin(y,(1.0-(ld)P[i].fi*x)/(ld)(P[i].se));
        }
        //cout<<x<<" "<<y<<endl;
        return x*p+y*q;
    };
    for(int q=0;q<70;q++){
        ld a=f((l+l+r)/3),b=f((l+r+r)/3);
        if(a>b) r=(l+r+r)/3;
        else l=(l+l+r)/3;
    }
    
    ld ans=f((l+r)/2);
    cout<<fixed<<setprecision(25)<<ans<<endl;
}