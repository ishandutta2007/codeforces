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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> m(N),need(N),diff(N);
    ll ma=-1;
    for(int i=0;i<N;i++){
        cin>>m[i];
        need[i]=m[i]+1;
        chmax(need[i],ma);
        chmax(ma,need[i]);
    }
    
    for(int i=N-1;i>=0;i--){
        diff[i]=need[i]-i;
        if(i<N-1) chmax(diff[i],diff[i+1]);
        chmax(need[i],diff[i]+i);
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=need[i]-(m[i]+1);
    }
    
    cout<<ans<<endl;
}