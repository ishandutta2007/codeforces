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



void preprocess()
{

}

struct node
{
	int a,b;
	node()
	{}
	node(int _a,int _b)
	{
		a=_a;
		b=_b;
	}
};

bool operator < (node q,node w)
{
	if(q.a+q.b != w.a+w.b) return q.a+q.b < w.a+w.b;
	return q.a > w.a;
}
	int n;

void solve()
{
	bool found=false;
	node ans;
	for(int i=0;i<=1000000;i++)
	{
		int s = n-4*i;
		if(s<0) continue;
		
		if(s%7 != 0) continue;
		node temp = node(i,s/7);
		if((!found) || temp<ans)
		{
			found=true;
			ans=temp;
		}
	}
	
	if(!found)
		printf("-1\n");
	else
	{
		for(int i=0;i<ans.a;i++)
			printf("4");
		for(int i=0;i<ans.b;i++)
			printf("7");	
		printf("\n");
	}
}

bool input()
{
	s(n);
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