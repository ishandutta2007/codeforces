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
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;ll K;cin>>N>>K;
    vector<ll> use;
    use.push_back(1);
    for(int q=0;q<100;q++){
        if(abs(use.back())>1e15) break;
        use.push_back(use.back()*K);
    }
    sort(all(use));
    use.erase(unique(all(use)),use.end());
    
    map<ll,ll> MA;
    ll ans=0;
    ll sum=0;
    MA[sum]++;
    for(int i=0;i<N;i++){
        ll x;cin>>x;
        sum+=x;
        for(ll a:use){
            if(MA.count(sum-a)) ans+=MA[sum-a];
        }
        MA[sum]++;
    }
    
    cout<<ans<<endl;
}