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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,P,Q,R;cin>>N>>P>>Q>>R;
    vector<ll> A(N);
    ll ans=-4e18;
    for(int i=0;i<N;i++) cin>>A[i];
    vector<ll> left(N),right(N);
    for(int i=0;i<N;i++){
        if(i) left[i]=max(left[i-1],A[i]*P);
        else left[i]=A[i]*P;
    }
    for(int i=N-1;i>=0;i--){
        if(i<N-1) right[i]=max(right[i+1],A[i]*R);
        else right[i]=A[i]*R;
    }
    
    for(int i=0;i<N;i++){
        chmax(ans,left[i]+A[i]*Q+right[i]);
    }
    
    cout<<ans<<endl;
}