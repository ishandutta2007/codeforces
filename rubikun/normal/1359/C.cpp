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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll h,c,t;cin>>h>>c>>t;
        if(h<=t){
            cout<<1<<"\n";
        }else if(h+c>=t+t){
            cout<<2<<"\n";
        }else{
            ll a=(h-t)/(2*t-h-c);
            pair<long double,ll> mi={INF,INF};
            
            for(ll x=max(0LL,a-2);x<=a+2;x++){
                long double y=(long double)((h*(x+1)+c*x))/(long double)(2*x+1);
                chmin(mi,mp(abs(y-t),2*x+1));
            }
            
            cout<<mi.se<<"\n";
        }
    }
}