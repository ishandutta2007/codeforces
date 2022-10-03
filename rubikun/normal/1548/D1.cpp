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
const int mod=1000000007,MAX=3100005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> cnt(4);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        a/=2;
        b/=2;
        a&=1;
        b&=1;
        cnt[a*2+b]++;
    }
    ll ans=0;
    for(int i=0;i<4;i++){
        if(cnt[i]>=3){
            ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        }
        if(cnt[i]>=2){
            for(int j=0;j<4;j++){
                if(j==i) continue;
                ans+=cnt[i]*(cnt[i]-1)*cnt[j]/2;
            }
        }
    }
    
    cout<<ans<<endl;
    
}