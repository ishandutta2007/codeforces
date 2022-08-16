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
int n,k;
VI lucky;
LL fact[16];

void preprocess()
{
	fact[0]=1;
	for(int i=1;i<=15;i++)
		fact[i] = i*fact[i-1];
}

void gen(LL cur)
{
	if(cur > 1e9) return;
	if(cur!=0) lucky.pb((int)cur);
	gen(cur*10+4);
	gen(cur*10+7);
}

VI getPerm(VI arr,int k)
{
	int n=arr.size();
	if(n==1) return arr;
	
	int first = (int)k/fact[n-1];
	
	VI temp;
	for(int i=0;i<n;i++)
		if(i!=first)
			temp.pb(arr[i]);
	VI ret=getPerm(temp, k-first*fact[n-1]);
			
	VI ans;
	ans.pb(arr[first]);
	for(int i=0;i<n-1;i++)
		ans.pb(ret[i]);
	return ans;
}


bool isLucky(int n)
{
	if(n==0) return true;
	int z=n%10;
	if(z!=4 && z!=7) return false;
	return isLucky(n/10);
}

void solve()
{
	if(n<15 && k>fact[n])
	{
		printf("-1\n");
		return;
	}
	
	int last = min(n,15);
	
	int tot=0;
	gen(0);
	sort(all(lucky));
	tot += INDEX(lucky,n-last+1);
	//printf("%d\n",tot);
	
	VI arr(last);
	for(int i=0;i<last;i++)
		arr[i] = n-last+i+1;
		
	arr = getPerm(arr,k-1);
		
	for(int i=0;i<last;i++)
	{
		//printf("%d %d\n",arr[i],n-last+i+1);
		if(isLucky(arr[i]) && isLucky(n-last+i+1))
			tot++;
	}
	
	printf("%d\n",tot);
}

bool input()
{
	s(n); s(k);
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