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
vector<ll> wh[MAX];

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// unordered_set<ll,custom_hash> SE or unordered_map<ll,int,custom_hash> MA

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        //cout<<300000*sqrt(300000)<<endl;
        int N,M;cin>>N>>M;
        vector<ll> A(N);
        map<ll,int> MA;
        for(int i=0;i<N;i++){
            cin>>A[i];
            MA[A[i]]++;
        }
        for(int i=0;i<=N;i++) wh[i].clear();
        for(auto a:MA){
            wh[a.se].push_back(a.fi);
        }
        vector<int> use;
        for(int i=0;i<=N;i++){
            sort(all(wh[i]));
            reverse(all(wh[i]));
            if(si(wh[i])) use.push_back(i);
        }
        unordered_set<ll,custom_hash> ng;
        for(int i=0;i<M;i++){
            ll a,b;cin>>a>>b;
            ng.insert((a<<32)+b);
            ng.insert((b<<32)+a);
        }
        
        ll ans=-1;
        
        for(auto a:MA){
            ll x=a.fi;
            for(int k:use){
                if(k>a.se) break;
                for(ll y:wh[k]){
                    if(x==y) continue;
                    if(ng.count((x<<32)+y)) continue;
                    chmax(ans,(x+y)*(a.se+k));
                    break;
                }
            }
        }
        
        assert(si(MA)*si(use)<=100000000);
        cout<<ans<<"\n";
    }
}