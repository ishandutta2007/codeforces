#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        ll N;cin>>N;
        if(N%4) cout<<"NO\n";
        else{
            cout<<"YES\n";
            vector<ll> ans(N);
            ll sum=0;
            for(int i=0;i<N/2;i++){
                ans[i]=2*(i+1);
                sum+=ans[i];
            }
            for(int i=N/2;i<N-1;i++){
                ans[i]=1+(i-N/2)*2;
                sum-=ans[i];
            }
            ans[N-1]=sum;
            
            for(ll a:ans) cout<<a<<" ";
            cout<<"\n";
        }
    }
}