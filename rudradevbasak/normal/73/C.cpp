//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
int dp[100][26][101];
char s[111];
int arr[111];
int K;
int m;
int bonus[26][26];
int n;

void preprocess()
{

}

void solve()
{
	for(int k=0;k<100;k++)
		for(int i=0;i<26;i++)
			for(int j=0;j<101;j++)
				dp[k][i][j]=-10000000;
	
	
	for(int i=0;i<26;i++)
	{
		if(i==arr[0]) 	dp[0][i][0]=0;
		else			dp[0][i][1]=0;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(j==arr[i])
			for(int k=0;k<101;k++)
			{
				for(int l=0;l<26;l++)
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][l][k]+bonus[l][j]);
			}
			
			else
			for(int k=0;k<100;k++)
			{
				for(int l=0;l<26;l++)
					dp[i][j][k+1] = max(dp[i][j][k+1], dp[i-1][l][k]+bonus[l][j]);
			}	
		}
	}
	
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<26;j++)
			printf("(%d,%d) : %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
		printf("\n");
	}*/
	
	int ans=-1000000;
	for(int j=0;j<26;j++)
		for(int k=0;k<=K;k++)
			ans=max(ans,dp[n-1][j][k]);
			
		printf("%d\n",ans);
}

bool input()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		arr[i]=s[i]-'a';
	s(K);
	s(m);
	
	//printf("%s %d %d\n",s,K,m);
	fill(bonus,0);
	char a,b;
	int x;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>x;
		//printf("%c %c %d\n",a,b,x);
		bonus[a-'a'][b-'a']=x;
	}
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}