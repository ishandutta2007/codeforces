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
const int mod=1000000007,MAX=2005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll K;cin>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    vector<ll> candi;
    
    for(int i=0;i<N;i++){
        for(ll j=1;j*j<=A[i];j++){
            candi.push_back(j);
            candi.push_back((A[i]+j-1)/j);
        }
    }
    
    sort(all(candi));
    candi.erase(unique(all(candi)),candi.end());
    
    candi.push_back(1LL<<55);
    
    ll ans=0;
    
    for(int t=0;t+1<si(candi);t++){
        ll left=candi[t]-1,right=candi[t+1];
        
        while(right-left>1){
            ll mid=(left+right)/2;
            ll sum=0;
            
            for(int i=0;i<N;i++){
                ll x=mid-A[i]%mid;
                if(x==mid) x=0;
                sum+=x;
            }
            
            if(sum<=K) left=mid;
            else right=mid;
        }
        
        if(left>=candi[t]) chmax(ans,left);
    }
    
    cout<<ans<<endl;
}