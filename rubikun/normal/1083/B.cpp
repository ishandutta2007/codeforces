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
const int mod=1000000007,MAX=500005;
const ll INF=1LL<<60;
ll dp[MAX];
ll N,K;
string S,T;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K;
    cin>>S>>T;
    
    ll diff=0;
    
    for(int i=0;i<N;i++){
        diff*=2;
        if(S[i]=='a'&&T[i]=='b'){
            diff++;
        }
        if(S[i]=='b'&&T[i]=='a'){
            diff--;
        }
        
        dp[i]=diff+1;
        if(dp[i]>=K){
            while(i<N){
                dp[i]=K;
                i++;
            }
            break;
        }
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++) ans+=dp[i];
    
    cout<<ans<<endl;
    
}