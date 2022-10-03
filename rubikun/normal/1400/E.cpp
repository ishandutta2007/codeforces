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
const int mod=1000000007,MAX=5005;
const ll INF=1LL<<60;
int A[MAX],dp[MAX][MAX];

int solve(int l,int r,int diff){
    if(dp[l][r]) return dp[l][r];
    if(l==r) return 0;
    if(r-l==1) return dp[l][r]=(A[l]!=diff);
    
    vector<pair<int,int>> S;
    for(int i=l;i<r;i++){
        S.push_back(mp(A[i]-diff,i));
    }
    sort(all(S));
    
    if(S.back().fi==0) return 0;
    
    if(S[0].fi==S.back().fi) return dp[l][r]=min(r-l,S[0].fi);
    
    int i=0;
    int res=S[0].fi;
    while(i<si(S)&&S[0].fi==S[i].fi){
        if(i==0) res+=solve(l,S[i].se,diff+S[0].fi);
        else res+=solve(S[i-1].se+1,S[i].se,diff+S[0].fi);
        i++;
    }
    i--;
    res+=solve(S[i].se+1,r,diff+S[0].fi);
    
    chmin(res,r-l);
    
    return dp[l][r]=res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    cout<<solve(0,N,0)<<endl;
    
    
}