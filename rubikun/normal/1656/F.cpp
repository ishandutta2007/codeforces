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
const int mod=998244353,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        ll a=0,b=0,sum=0;
        for(int i=0;i<N;i++){
            if(i) a+=A[0]+A[i];
            if(i<N-1) b+=A[i]+A[N-1];
            sum+=A[i];
        }
        if(a>0||b<0) cout<<"INF\n";
        else{
            ll ans=-(1LL<<60);
            ll pre=0,suf=sum;
            for(int i=0;i+1<N;i++){
                pre+=A[i];
                suf-=A[i];
                ll z=sum+A[0]*(N-1-i)+A[N-1]*(i+1)-A[0]-A[N-1];
                ll t=A[0]*suf+A[N-1]*pre-A[0]*A[N-1];
                chmax(ans,z*(-A[i])+t);
                chmax(ans,z*(-A[i+1])+t);
            }
            cout<<ans<<"\n";
        }
    }
}