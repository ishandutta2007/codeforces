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
VVI arr;
VI row;
VI col;
int n,m;



void preprocess()
{

}

void solve()
{
	row.resize(n);
	col.resize(m);
	for(int i=0;i<n;i++)
		row[i]=0;
	for(int j=0;j<m;j++)
		col[j]=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j]>0)
			{
				row[i]=1;
				col[j]=1;
			}
			
	for(int i=0;i<n;i++)
	{
		if(row[i]==0) continue;
		int mode1=0;
		int mode2=0;
		
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0) continue;
			
			if(arr[i][j]==1 || arr[i][j]==2)
			{
				if(j&1) mode1=1;
				else mode2=1;
			}
			else
			{
				if(j&1) mode2=1;
				else mode1=1;
			}
		}
		
		if(mode1==1 && mode2==1)
		{
			cout<<0<<endl;
			return;
		}
	}
		

	for(int j=0;j<m;j++)
	{
		if(col[j]==0) continue;
		int mode1=0;
		int mode2=0;
		
		for(int i=0;i<n;i++)
		{
			if(arr[i][j]==0) continue;
			
			if(arr[i][j]==2 || arr[i][j]==3)
			{
				if(i&1) mode1=1;
				else mode2=1;
			}
			else
			{
				if(i&1) mode2=1;
				else mode1=1;
			}
		}
		
		if(mode1==1 && mode2==1)
		{
			cout<<0<<endl;
			return;
		}
	}	

	int rl=0,cl=0;
	for(int i=0;i<n;i++)
		if(row[i]==0) rl++;
		
	for(int j=0;j<m;j++)
		if(col[j]==0) cl++;
		
	
	int p=rl+cl;
	LL ans=1;
	LL x=2;
	LL mod = 1000003;
	while(p>0)
	{
		if(p&1)
			ans = (ans*x) % mod;
		x = (x*x) % mod;
		p >>= 1;
	}
	
	cout<<ans<<endl;
		
	
		
		
}

bool input()
{
	s(n); s(m);
	arr.clear();
	arr.resize(n);
	
	char temp[500005];
	for(int i=0;i<n;i++)
	{
		arr[i].resize(m);
		scanf("%s",temp);
		for(int j=0;j<m;j++)
		{
			if(temp[j]=='.')
				arr[i][j]=0;
			else
				arr[i][j]=temp[j]-'0';
		}
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