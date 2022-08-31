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
#define DREP(a)						sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin()

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
bool arr[200][200];
int mn[200],mx[200];
int m,n;



void preprocess()
{

}

void solve()
{
	for(int i=0;i<n;i++)
	{
		mn[i]=200;
		mx[i]=-1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j])
			{
				if(j<mn[i])
					mn[i]=j;
				if(j>mx[i])
					mx[i]=j;
			}
			
	int r=0,c=0;
	int dir=+1;
	int cnt=0;
	
	int low=-1;
	for(int i=0;i<n;i++)
		if(mx[i] >= 0) low=i;
		
	
	for(int i=0;i+1<=low;i++)
	{
		if(dir>0)
		{
			int z=max(c,max(mx[i],mx[i+1]));
			cnt+= z-c;
			c=z;
			
			r++;
			dir=-dir;
			cnt++;
		}
		else
		{
			int z=min(c,min(mn[i],mn[i+1]));
			cnt+= c-z;
			c=z;
			
			r++;
			dir=-dir;
			cnt++;
			
		}
	}
	
	int i=low;
	if(dir>0)
	{
		int z=max(mx[i],c);
		cnt+= z-c;
	}
	else
	{
		int z=min(mn[i],c);
		cnt+= c-z;
	}
	
	cout<<cnt<<endl;
	
}

bool input()
{
	s(n); s(m);
	char temp[200];
	fill(arr,false);
	for(int i=0;i<n;i++)
	{
		scanf("%s",temp);
		for(int j=0;j<m;j++)
			if(temp[j]=='W')
				arr[i][j]=true;
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