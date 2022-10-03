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
const int mod=998244353,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll X,D;cin>>X>>D;
    vector<ll> ans;
    ll now=1;
    
    while(X){
        for(int t=40;t>=1;t--){
            if((1LL<<t)-1<=X){
                for(int i=0;i<t;i++) ans.push_back(now);
                X-=(1LL<<t)-1;
                now+=2e9;
                break;
            }
        }
    }
    
    cout<<si(ans)<<endl;
    for(ll x:ans) cout<<x<<" ";
    cout<<endl;
}