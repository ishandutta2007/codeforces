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
#define ss(n) 						scanf("%s",n)
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
vector<PII> arr;

bool isLucky(int n)
{
	while(n)
	{
		int z=n%10;
		if(z!=4 && z!=7) return false;
		n /= 10;
	}
	return true;
}

int N;
int to[100005],from[100005];
bool reach[100005];
bool done[100005];


void preprocess()
{

}

void solve()
{
	bool found=false;
	int spcl=-1;
	for(int i=0;i<N;i++)
		if(isLucky(arr[i].first))
		{
			found=true;
			spcl=arr[i].second;
		}
			
	if(!found)
	{
		bool ok=true;
		for(int i=0;i<N;i++)
			if(arr[i].second!=i)
				ok=false;
				
		if(ok)
			printf("0\n");
		else
			printf("-1\n");
		return;
	}
	
	fill(reach,false);
	int x=to[spcl];
	while(x!=spcl)
	{
		reach[x]=true;
		x=to[x];
	}
	
	reach[spcl]=true;
	
	fill(done,false);
	
	int cnt=0;
	
	for(int i=0;i<N;i++)
	{
		if(done[i] || reach[i]) continue;
		
		cnt++;
		
		int x=from[i];
		int y=i;
		while(x!=i)
		{
			done[x]=true;
			cnt++;
			y=x;
			x=from[x];
			
		}
		
		cnt++;
		done[i]=true;
	}
	
	x=from[spcl];
	int y=spcl;
	while(x!=spcl)
	{
		cnt++;
		y=x;
		x=from[x];
	}
	
	fill(done,false);
	
	
	printf("%d\n",cnt);
	
	for(int i=0;i<N;i++)
	{
		if(done[i] || reach[i]) continue;
		
		printf("%d %d\n",spcl+1,i+1);
		
		int x=from[i];
		int y=i;
		while(x!=i)
		{
			done[x]=true;
			printf("%d %d\n",x+1,y+1);
			y=x;
			x=from[x];
			
		}
		
		printf("%d %d\n",spcl+1,to[i]+1);
		done[i]=true;
	}
	
	x=from[spcl];
	y=spcl;
	while(x!=spcl)
	{
		printf("%d %d\n",x+1,y+1);
		y=x;
		x=from[x];
	}
	
	
	
	
}

bool input()
{
	s(N);
	arr.resize(N);
	int x;
	for(int i=0;i<N;i++)
	{
		s(x);
		arr[i] = mp(x,i);
	}
	sort(arr.begin(),arr.end());
	
	for(int i=0;i<N;i++)
	{
		to[arr[i].second]=i;
		from[i]=arr[i].second;
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