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
const int mod=1000000007,MAX=100005,INF=1<<30;
int N;
bool seen[MAX];
int dp[MAX];
int A[MAX];

int solve(int u){
    if(seen[u]) return dp[u];
    if(u==N) return 0;
    seen[u]=true;
    int res=0;
    for(int i=u;i<N;i++){
        int sum=0;
        sum+=A[i];
        int rem=0;
        for(int j=i+1;j<N;j++) rem+=A[j];
        rem-=solve(i+1);
        sum+=rem;
        chmax(res,sum);
    }
    return dp[u]=res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    int ans=solve(0);
    int rem=-ans;
    for(int i=0;i<N;i++) rem+=A[i];
    cout<<rem<<" "<<ans<<endl;
}