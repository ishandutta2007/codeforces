// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

#pragma GCC Optimize("Ofast")

const ll maxn=110;

int n,k;
string s[3];
int dp[3][maxn];

inline bool ok(char ch){
	return (ch=='.'||ch=='$');
}
inline bool move1(int x,int y){
	return (ok(s[x][y])&&ok(s[x][y+1])&&ok(s[x-1][y+1])&&ok(s[x-1][y+2])&&ok(s[x-1][y+3]));
}
inline bool move2(int x,int y){
	return (ok(s[x][y])&&ok(s[x][y+1])&&ok(s[x][y+2])&&ok(s[x][y+3]));
}
inline bool move3(int x,int y){
	return (ok(s[x][y])&&ok(s[x][y+1])&&ok(s[x+1][y+1])&&ok(s[x+1][y+2])&&ok(s[x+1][y+3]));
}
bool dfs(int x,int y){
	if(s[x][y]=='$')
		return 1;
	if(dp[x][y]!=0)
		return (dp[x][y]==1);
	dp[x][y]=1;
	if(x!=0&&move1(x,y))
		if(dfs(x-1,y+3))
			return 1;
	if(move2(x,y))
		if(dfs(x,y+3))
			return 1;
	if(x!=2&&move3(x,y))
		if(dfs(x+1,y+3))
			return 1;
	dp[x][y]=-1;
	return 0;
}

int main(){
	int t;cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		cin>>n>>k;
		REP(i,3)
			cin>>s[i];
		REP(i,3)
			s[i]+="$$$$$$$$";
		int p;
		REP(i,3)
			if(s[i][0]=='s')
				p=i;
		s[p][0]='.';
		cout<<(dfs(p,0)?"YES":"NO")<<endl;
	}
}