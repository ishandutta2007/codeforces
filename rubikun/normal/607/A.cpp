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
const int mod=998244353,MAX=100005,INF=1<<30;

int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].fi>>A[i].se;
    }
    A.push_back(mp(-INF,0));
    sort(all(A));
    
    for(int i=1;i<=N;i++){
        auto it=lower_bound(all(A),mp(A[i].fi-A[i].se,-1));
        it--;
        dp[i]=dp[it-A.begin()]+1;
    }
    int ans=0;
    for(int i=1;i<=N;i++) chmax(ans,dp[i]);
    
    cout<<N-ans<<endl;
}