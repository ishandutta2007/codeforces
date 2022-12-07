#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int ca1[5010][5010];//iFjh@
int ca2[5010][5010];//nFAiFjh@
int dp[10000010];
int len1[1000010],len2[1000010];
int p;
int ch(int a,int b){
	return len2[a]+b-1;
}
lint cal(int a,int b){
	if(b>len1[a]) return 0;
	if(b<2) return dp[ch(a,b)];
	return dp[ch(a,b)]+p-dp[ch(a,b-1)];
}
int main()
{
	int i,j,n,m;
	len2[0]=0;
	cin>>n>>m>>p;
	rep(i,n){
		scanf("%d",&len1[i]);len2[i+1]=len2[i]+len1[i];
	}
	REP(i,1,5010) REP(j,i,5010){
		if(i<2){
			if(j<2) ca1[i][j]=1;else ca1[i][j]=0;
		}
		else{
			ca1[i][j]=(int)(((lint)ca1[i][j-1]*(i-1)+(lint)ca1[i-1][j-1]*i)%p);
		}
	}
//	rep(i,n+1) cout<<len1[i]<<endl;
	ca2[1][1]=m;
	REP(i,1,5005) REP(j,i,5005){
		ca2[i][j+1]=(int)(((lint)ca2[i][j]*(i-1)+ca2[i][j+1])%p);
		ca2[i+1][j+1]=(int)(((lint)ca2[i][j]*(m-i)+ca2[i+1][j+1])%p);
	}
//	cout<<ca2[2][2]<<endl;
	
	dp[0]=ca2[1][len1[0]];
	REP(i,1,len1[0]) dp[i]=(dp[i-1]+ca2[i+1][len1[0]])%p;
	
	rep(i,n-1) REP(j,1,len1[i+1]+1){
		dp[ch(i+1,j)]=(int)(((lint)dp[len2[i+1]-1]*ca2[j][len1[i+1]])%p);
//		if(i==1 && j==2) cout<<dp[ch(i+1,j)]<<"a"<<endl;
		dp[ch(i+1,j)]=(int)((dp[ch(i+1,j)]+p-(int)((cal(i,j)*ca1[j][len1[i+1]])%p))%p);
		if(j>1) dp[ch(i+1,j)]=(dp[ch(i+1,j)]+dp[ch(i+1,j-1)])%p;
	}
	rep(i,n){
//		rep(j,len1[i]) cout<<dp[len2[i]+j]<<" ";cout<<endl;
	}
	cout<<dp[len2[n]-1]<<endl;
	return 0;
}