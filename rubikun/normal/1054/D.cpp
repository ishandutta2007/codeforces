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
    
    int N,K;cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    int X=(1<<K)-1;
    
    map<int,int> MA;
    MA[0]++;
    
    int now=0;
    
    for(int i=0;i<N;i++){
        now^=A[i];
        MA[now]++;
    }
    
    ll ans=ll(N)*(N+1)/2;
    
    for(auto x:MA){
        if(x.fi>=(1<<(K-1))){
            if(MA[X-x.fi]>0) continue;
        }
        ll a=MA[x.fi]+MA[X-x.fi];
        ll b=a/2,c=a-b;
        ans-=b*(b-1)/2;
        ans-=c*(c-1)/2;
    }
    
    cout<<ans<<endl;
}