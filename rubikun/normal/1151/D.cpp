#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,ll>> S(N);
    for(int i=0;i<N;i++) cin>>S[i].first>>S[i].second;
    
    sort(all(S),[](pair<ll,ll> a,pair<ll,ll> b){
        return a.first-a.second>b.first-b.second;
    });
    
    ll ans=0;
    for(ll i=0;i<N;i++){
        ans+=S[i].first*i+S[i].second*(N-1-i);
    }
    
    cout<<ans<<endl;
}