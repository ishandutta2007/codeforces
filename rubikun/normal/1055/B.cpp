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
    
    int N,Q;ll L;cin>>N>>Q>>L;
    vector<ll> now(N);
    for(int i=0;i<N;i++) cin>>now[i];
    
    int ans=0;
    for(int i=0;i<N;i++){
        if(now[i]>L&&(i==0||now[i-1]<=L)) ans++;
    }
    
    while(Q--){
        int t;cin>>t;
        if(t==0) cout<<ans<<"\n";
        else{
            int a,b;cin>>a>>b;
            a--;
            bool f=false;
            if(now[a]<=L) f=true;
            now[a]+=b;
            if(now[a]<=L) continue;
            if(!f) continue;
            
            if(a==0||now[a-1]<=L) ans++;
            if(a<N-1&&now[a+1]>L) ans--;
        }
    }
}