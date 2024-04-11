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
const int mod=1000000007,MAX=20005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    ll ans=0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=M;j++){
            int x=i*i+j*j;
            if(x%M) continue;
            ll a=(N-(i-1)+M-1)/M,b=(N-(j-1)+M-1)/M;
            ans+=a*b;
        }
    }
    
    cout<<ans<<endl;
}