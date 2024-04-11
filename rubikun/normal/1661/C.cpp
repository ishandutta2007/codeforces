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
const int mod=998244353,MAX=32768;
const ll INF=1LL<<60;

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
        ll ans=INF;
        for(ll d=A.back();d<=A.back()+1;d++){
            ll a=0,b=0;
            for(int i=0;i<N;i++){
                if((d-A[i])&1) a++;
                b+=(d-A[i])/2;
            }
            ll left=-1,right=INF;
            while(right-left>1){
                ll mid=(left+right)/2;
                ll x=(mid+1)/2,y=mid-x;
                if(x<a) left=mid;
                else{
                    ll rem=(x-a)/2+y;
                    if(rem>=b) right=mid;
                    else left=mid;
                }
            }
            chmin(ans,right);
        }
        cout<<ans<<"\n";
    }
}