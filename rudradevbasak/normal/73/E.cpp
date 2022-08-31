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
int n,x;
const int lim=1500000;
bool arr[lim];
bool prime[lim];


void preprocess()
{

}

void solve()
{
	if(x==2)
	{
		printf("0\n");
		return;
	}
	
	if(arr[1])
	{
		printf("1\n");
		return;
	}
	
	if(x>=lim)
	{
		printf("-1\n");
		return;
	}
	
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<lim;i++)
		prime[i]=true;
		
	for(int i=2;i<lim;i++)
	{
		if(prime[i])
			for(int j=i+i;j<lim;j+=i)
				prime[j]=false;
	}
	
	/*
	for(int i=2;i<100;i++)
		if(prime[i])
			printf("%d\n",i);
	*/
			
	for(int i=2;i<x;i++)
	{
		if(prime[i] && !arr[i])
		{
			printf("-1\n");
			return;
		}
	}
	
	int ans=0;
	for(int i=2;i<x;i++)
		if(prime[i]) 
			ans++;
			
	printf("%d\n",ans);
	
	
}

bool input()
{
	s(n); s(x);
	int a;
	fill(arr,false);
	for(int i=0;i<n;i++)
	{
		s(a);
		if(a<lim)
			arr[a]=true;
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