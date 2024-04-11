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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;ll X;cin>>N>>X;
    vector<ll> D(2*N),sum(2*N+1),sump(2*N+1);
    for(int i=0;i<N;i++){
        cin>>D[i];
        D[N+i]=D[i];
    }
    
    for(int i=1;i<=2*N;i++){
        sum[i]=sum[i-1];
        sum[i]+=D[i-1];
    }
    
    for(int i=1;i<=2*N;i++){
        sump[i]=sump[i-1];
        sump[i]+=(D[i-1]+1)*D[i-1]/2;
    }
    
    ll ans=0;
    
    int left=0;
    
    for(int i=1;i<=2*N;i++){
        if(sum[i]<X) continue;
        while(sum[i]-sum[left]>=X) left++;
        left--;
        ll diff=sum[i]-sum[left]-X;
        chmax(ans,sump[i]-sump[left]-(diff+1)*diff/2);
    }
    
    cout<<ans<<endl;
}