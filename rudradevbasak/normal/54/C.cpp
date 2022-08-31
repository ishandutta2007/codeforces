//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>


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

LL power10(int k)
{
	LL prod=1;
	for(int i=0;i<k;i++)
		prod*=10;
	return prod;
}

int nod(LL a)
{
	int ans=0;
	while(a>0)
	{
		ans++;
		a=a/10;
	}
	return ans;
}

LL lessthan(LL a)
{
	if(a<=0) return 0;
	
	int n=nod(a)-1;
	LL sum=0,term=1;
	for(int i=0;i<n;i++)
	{
		sum+=term;
		term*=10;
	}
	LL base=power10(n);
	if(a>=base+base)
		sum+=base;
	else
		sum+=(a-base+1);
	return sum;
}

double prob(LL a,LL b)
{
	double num=lessthan(b)-lessthan(a-1);
	return num/(b-a+1);
}



LL lt[1001],rt[1001];
double p[1001];
double dp[1001][1001];	
int K,N;

void preprocess()
{

}

void solve()
{
	for(int i=0;i<N;i++)
		p[i]=prob(lt[i],rt[i]);

	fill(dp,0);
	dp[0][0]=1-p[0];
	dp[0][1]=p[0];

	for(int i=1;i<N;i++)
	{
		dp[i][0]=(1-p[i])*dp[i-1][0];
		for(int j=1;j<=i+1;j++)
			dp[i][j]=(1-p[i])*dp[i-1][j] + p[i]*dp[i-1][j-1];
	}

	double sum=0;
	for(int j=0;j<=N;j++)
	{
		if(j>=(N*K)/100.0-EPS)
			sum+=dp[N-1][j];
	}
	printf("%.15lf\n",sum);
	
}

bool input()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>lt[i]>>rt[i];
	}
	cin>>K;
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