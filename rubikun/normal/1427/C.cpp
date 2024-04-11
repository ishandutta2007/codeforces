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
const int INF=1<<30;
//const ll INF=1LL<<60;

int dp[MAX],ma[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int R,N;cin>>R>>N;
    for(int i=1;i<=N;i++) dp[i]=-INF;
    dp[0]=0;
    ma[0]=0;
    
    vector<pair<int,int>> S(N+1);
    vector<int> T(N+1);
    
    S[0]={1,1};
    
    for(int i=1;i<=N;i++) cin>>T[i]>>S[i].fi>>S[i].se;
    
    for(int i=1;i<=N;i++){
        for(int j=i-1;j>=0;j--){
            if(T[i]-T[j]>=1000){
                chmax(dp[i],ma[j]+1);
                break;
            }
            if(abs(S[i].fi-S[j].fi)+abs(S[i].se-S[j].se)<=T[i]-T[j]) chmax(dp[i],dp[j]+1);
        }
        ma[i]=max(ma[i-1],dp[i]);
    }
    
    //for(int i=0;i<=N;i++) cout<<dp[i]<<" ";
    //cout<<endl;
    
    cout<<ma[N]<<endl;
}