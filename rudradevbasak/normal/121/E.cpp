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
#define INDEX(arr,ind)				lower_bound(all(arr),ind)-arr.begin())

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
bool isl[10005];
int n,m;
int arr[100005];

bool isLucky(int n)
{
	if(n==0) return true;
	int z=n%10;
	if(z!=4 && z!=7) return false;
	return isLucky(n/10);
}

void preprocess()
{
	for(int i=0;i<=10000;i++)
		isl[i] = isLucky(i);
}

void solve()
{
	char temp[10];
	int l,r,d;
	int prevl,prevr,previ=-100,prevcnt;
	for(int i=0;i<m;i++)
	{
		ss(temp);
		if(temp[0]=='a')
		{
			s(l); s(r); s(d);
			for(int i=l;i<=r;i++)
				arr[i]+=d;
		}
		else
		{
			s(l); s(r);
			int cnt=0;
			
			if(previ==i-1 && prevl==l && prevr==r)
				cnt = prevcnt;
			else
				for(int j=l;j<=r;j++)
					if(isl[arr[j]])
						cnt++;
						
			printf("%d\n",cnt);
			
			previ=i;
			prevl=l;
			prevr=r;
			prevcnt=cnt;
		}
	}
			
			
}

bool input()
{
	s(n); s(m);
	for(int i=0;i<n;i++)
		s(arr[i+1]);
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