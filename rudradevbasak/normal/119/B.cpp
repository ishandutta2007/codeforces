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
int n,k,m;
VI prof;
int q;
VVI cards;
bool done[105];


void preprocess()
{

}

void solve()
{
	fill(done,false);
	double worst = 101;
	double best = -1;
	for(int i=0;i<cards.size();i++)
	{
		double sum=0;
		for(int j=0;j<m;j++)
		{
			sum+=prof[cards[i][j]-1];
			done[cards[i][j]]=true;
		}
		
		sum /= m;
		//cout<<sum<<endl;
		worst=min(worst,sum);
		best=max(best,sum);
	}
	
	VI left;
	for(int i=1;i<=n;i++)
		if(!done[i])
			left.pb(prof[i-1]);
	sort(all(left));
			
	if(cards.size() < k)
	{
		double sum1=0,sum2=0;
		for(int i=0;i<m;i++)
		{
			sum1 += left[i];
			sum2 += left[left.size()-1-i];
		}
		
		sum1/=m;
		sum2/=m;
		
		worst=min(worst,sum1);
		best=max(best,sum1);
		
		worst=min(worst,sum2);
		best=max(best,sum2);
	}
	
	printf("%.9lf %.9lf\n",worst,best);
		
		
}

bool input()
{
	s(n); s(k);
	m=n/k;
	prof.resize(n);
	for(int i=0;i<n;i++)
		s(prof[i]);
		
	s(q);
	for(int i=0;i<q;i++)
	{
		VI temp(m);
		for(int j=0;j<m;j++)
			s(temp[j]);
		sort(all(temp));
		cards.pb(temp);
	}
	
	DREP(cards);
	//printf("%d\n",cards.size());
		
	
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