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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<55;

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
    if(N&1){
        N--;
        A.pop_back();
    }
    
    ll ans=0;
    
    for(int s=0;s<N;s+=2){
        ll sum=0;
        ll left=-INF;
        for(int t=s+1;t<N;t++){
            if(t&1) sum+=A[t];
            else sum-=A[t];
            
            if(t&1){
                //[left,sum]
                ll l=left,r=sum;
                chmax(l,1LL);
                chmin(r,A[s]);
                ans+=max(0LL,r-l+1);
                chmax(left,sum);
                //cout<<s<<" "<<t<<" "<<l<<" "<<r<<endl;
            }
        }
    }
    
    cout<<ans<<endl;
}