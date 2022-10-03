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
const int mod=998244353,MAX=100005;
const ll INF=1LL<<50;
int N,K;
int A[MAX];
ll dp[23][MAX];
int freq[MAX];
int Lnow,Rnow;
ll sum;

ll f(int l,int r){
    while(Lnow>l){
        Lnow--;
        sum+=freq[A[Lnow]];
        freq[A[Lnow]]++;
    }
    while(Rnow<r){
        Rnow++;
        sum+=freq[A[Rnow-1]];
        freq[A[Rnow-1]]++;
    }
    while(Lnow<l){
        if(Lnow) freq[A[Lnow]]--;
        if(Lnow) sum-=freq[A[Lnow]];
        Lnow++;
    }
    while(Rnow>r){
        freq[A[Rnow-1]]--;
        sum-=freq[A[Rnow-1]];
        Rnow--;
    }
    return sum;
}

struct dat{
    int t;
    int l;
    int r;
    int L;
    int R;
};
queue<dat> Q;

void solve(int t,int l,int r,int L,int R){
    if(l==r){
        if(Q.empty()) return;
        auto u=Q.front();Q.pop();
        solve(u.t,u.l,u.r,u.L,u.R);
        return;
    }
    int m=(l+r)/2;
    pair<ll,int> mi=mp(INF*10,-1);
    
    for(int x=min(R-1,m);x>=L;x--){
        chmin(mi,mp(dp[t][x-1]+f(x,m+1),x));
    }
    //cout<<t<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<m<<" "<<mi.fi<<" "<<mi.se<<endl;
    
    dp[t+1][m]=mi.fi;
    Q.push({t,l,m,L,mi.se+1});
    Q.push({t,m+1,r,mi.se,R});
    
    auto u=Q.front();Q.pop();
    solve(u.t,u.l,u.r,u.L,u.R);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>A[i+1];
        A[i+1]--;
    }
    
    for(int i=0;i<23;i++){
        for(int j=0;j<MAX;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    
    Lnow=0;
    Rnow=1;
    
    for(int t=0;t<K;t++){
        solve(t,1,N+1,1,N+1);
    }
    
    cout<<dp[K][N]<<endl;
}