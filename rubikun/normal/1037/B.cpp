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
    
    int N;ll S;cin>>N>>S;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        if(i==N/2){
            ans+=abs(S-A[i]);
        }else if(i<N/2){
            if(A[i]>S) ans+=A[i]-S;
        }else{
            if(A[i]<S) ans+=S-A[i];
        }
    }
    
    cout<<ans<<endl;
}