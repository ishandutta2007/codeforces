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
int n,m,k;
int arr[100005];
int largest;


void preprocess()
{

}

void solve()
{
	if(n==1)
	{
		LL total = m;
		total *= k;
		if(total > arr[0])
			total=arr[0];
		printf("%d\n",total);
		return;
	}
	if(n%2 == 0)
	{
		printf("0\n");
		return;
	}
	LL step =(n+1)/2;
	LL once = m/step;
	LL total = once*k;
	if(total > largest)
		total = largest;
	cout<<total<<endl;
	
	
}

bool input()
{
	s(n);
	s(m);
	s(k);
	largest=INF;
	for(int i=0;i<n;i++)
	{
		s(arr[i]);
		if(i%2 == 0)
			largest=min(largest,arr[i]);
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