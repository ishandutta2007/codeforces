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
    
    ll N;cin>>N;
    vector<ll> h(N),ans(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>h[i];
        sum+=h[i];
    }
    ll a=sum/N-N;
    while(1){
        if((2*a+N-1)*N/2<=sum) a++;
        else break;
    }
    a--;
    
    sum-=(2*a+N-1)*N/2;
    for(int i=0;i<sum;i++) ans[i]++;
    
    for(int i=0;i<N;i++) ans[i]+=(a+i);
    
    for(ll a:ans) cout<<a<<" ";
    cout<<endl;
}