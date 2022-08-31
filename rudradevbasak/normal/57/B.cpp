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
LL d[100005];
LL s[100005];
int n,m,k;



void preprocess()
{

}

void solve()
{

}

bool input()
{
	fill(d,0ll);
	fill(s,0ll);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a]++;
		d[b+1]--;
		s[a]+=c;
		s[b+1]-=c+b+1-a;
	}
	LL ans=0;
	for(int i=0;i<k;i++)
	{
		int k; cin>>k;
		
		
		for(int j=k;j>=0;j--)
			ans+=d[j]*(k-j);
		for(int j=0;j<=k;j++)
			ans+=s[j];
			
		
	}
	cout<<ans<<endl;	
	return true;
}


int main()
{
	input();

}