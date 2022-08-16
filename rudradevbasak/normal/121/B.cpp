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
int n,k;
char str[100005];

void preprocess()
{

}

void solve()
{
	for(int i=0;i+1<n;i++)
	{
		if(k==0) break;
		if(!(str[i]=='4' && str[i+1]=='7')) continue;
		//printf("%d\n",i);
		if((i&1)==0)
		{
			//printf("%d\n",i);
			str[i+1]='4';
			k--;
			continue;
		}
		
		if(i==0 || str[i-1]!='4')
		{
			str[i]='7';
			k--;
			continue;
		}
		
		//printf("%d %c %c %c\n",i,str[i-1],str[i],str[i+1]);
		k = k&1;
		if(k)
			str[i]='7';
		break;
	}
	
	printf("%s\n",str);
	
}

bool input()
{
	s(n); s(k);
	ss(str);
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