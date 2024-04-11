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
const int mod=998244353,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll ans=1LL<<60;
    
    for(int m=0;m<N;m++){
        ll sum=0;
        ll la=0;
        for(int i=m-1;i>=0;i--){
            ll need=(la+1+A[i]-1)/A[i];
            sum+=need;
            la=need*A[i];
        }
        la=0;
        for(int i=m+1;i<N;i++){
            ll need=(la+1+A[i]-1)/A[i];
            sum+=need;
            la=need*A[i];
        }
        chmin(ans,sum);
    }
    
    cout<<ans<<endl;
}