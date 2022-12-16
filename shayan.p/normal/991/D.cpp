// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll dp[maxn][5];// onaii ke bit 1 hast bayad khali bashe va pawn ham nabashe

int main(){
    string s[2];
    cin>>s[0]>>s[1];
    ll n=sz(s[0]);
    dp[0][1]=dp[0][2]=dp[0][3]=-1;
    
    FOR(i,1,n){
	ll A=-1,B=-1,C=-1,D=-1;
	if(s[0][i-1]=='0')
	    A=(dp[i-1][3]==-1?-1:(1+dp[i-1][3]));
	if(s[1][i-1]=='0')
	    B=(dp[i-1][3]==-1?-1:(1+dp[i-1][3]));
	if(s[0][i-1]=='0'&&s[1][i-1]=='0')
	    C=(dp[i-1][1]==-1?-1:(1+dp[i-1][1]));
	if(s[0][i-1]=='0'&&s[1][i-1]=='0')
	    D=(dp[i-1][2]==-1?-1:(1+dp[i-1][2]));
	dp[i][0]=max(dp[i-1][0],max(A,max(B,max(C,D))));
	dp[i][1]=max(dp[i-1][0],B);
	dp[i][2]=max(dp[i-1][0],A);
	dp[i][3]=dp[i-1][0];
	if(s[0][i-1]=='X')
	    dp[i][1]=dp[i][3]=-1;
	if(s[1][i-1]=='X')
	    dp[i][2]=dp[i][3]=-1;
    }
    cout<<dp[n][0];
}