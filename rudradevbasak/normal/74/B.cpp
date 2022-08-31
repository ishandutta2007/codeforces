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
int n,m,k;
bool incr;
string s;
int len;

bool dp[300][51];

void preprocess()
{

}

void solve()
{
	fill(dp,false);
	dp[0][m]=true;
	int pos=k;
	
	for(int i=0;i<len-1;i++)
	{
		if(s[i]=='1')
		{
			//printf("idle !\n");
			if(incr) pos++;
			else pos--;
			if(pos==n) incr=false;
			if(pos==1) incr=true;
			
			for(int j=0;j<=n;j++)
				if(j!=pos)
					dp[i+1][j]=true;
					

		}
		else
		{
			//printf("moving !\n");
			int newpos;
			if(incr) newpos=pos+1;
			else	newpos=pos-1;
			//printf("pos %d newpos %d\n",pos,newpos);
			
			for(int j=1;j<=n;j++)
			{
				if(!dp[i][j]) continue;
				int temp=j-1;
				if(temp>=1 && temp<=n && temp!=pos && temp!=pos && temp!=newpos)
					dp[i+1][temp]=true;
				temp=j;
				if(temp>=1 && temp<=n && temp!=pos && temp!=pos && temp!=newpos)
					dp[i+1][temp]=true;
				temp=j+1;
				if(temp>=1 && temp<=n && temp!=pos && temp!=pos && temp!=newpos)
					dp[i+1][temp]=true;
			}
			
			if(incr) pos++;
			else pos--;
			if(pos==n) incr=false;
			if(pos==1) incr=true;
			
			bool found=false;
			for(int j=1;j<=n;j++)
			{
				if(dp[i+1][j])
				{
					found=true;
					//printf("Found %d %d\n",i+1,j);
					//break;
				}
			}
			if(!found)
			{
				printf("Controller %d\n",i+1);
				return;
			}
		}
	}
	printf("Stowaway\n");
			
				
}

bool input()
{
	s(n); s(m); s(k);
	string t1,t2;
	cin>>t1>>t2;
	incr = (t2[0]=='t');
	cin>>s;
	len=s.length();
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