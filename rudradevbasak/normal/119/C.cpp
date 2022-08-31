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

struct task
{
	LL a,b;
	int c,ind;
	
	task(LL _a, LL _b, int _c,int _ind)
	{
		a=_a;
		b=_b;
		c=_c;
		ind=_ind;
	}
};

bool operator <(task x,task y)
{
	return x.c < y.c;
}

vector<task> tk;
int n,m,k;


void preprocess()
{

}

LL dp[51][101][51];
int par[51][101][51];
LL part[51][101][51];


LL memo(int a,LL b,int c)
{
	//printf("%d %lld %d\n",a,b,c);
	
	if(b<0 || b>tk[a].b-tk[a].a) return -1;
	LL &z = dp[a][b][c];
	if(z>=-1) return z;
	
	LL tcur = tk[a].a+b;
	if(tcur > tk[a].b) return z = -1;
	
	if(c==1)
	{
		return z = tcur;
	}
	
	bool ok = ((tcur%k)==0);
	LL best=-1,bestp=-1,bestpt=-1;
	for(int i=0;i<a;i++)
	{
		if(!(tk[i]<tk[a])) continue;
		LL x = memo(i, tcur-k-tk[i].a, c-1);
		if(x>best)
		{
			best=x;
			bestp=i;
			bestpt=tcur-k-tk[i].a;
		}
		
		if(ok)
		{
			LL x = memo(i, tcur/k-tk[i].a, c-1);
			if(x>best)
			{
				best=x;
				bestp=i;
				bestpt=tcur/k-tk[i].a;
			}
		}
	}
	
	
	if(best>0)
	{
		par[a][b][c]=bestp;
		part[a][b][c]=bestpt;
		return z = best + tcur;
	}
	else
		return z = -1;
}

void doit(int a,LL b,int c)
{
	if(c>1)
		doit(par[a][b][c], part[a][b][c], c-1);
	cout<<tk[a].ind<<" "<<(tk[a].a+b)<<endl;
}

void solve()
{
	for(int i=0;i<=50;i++)
		for(int j=0;j<=100;j++)	
			for(int k=0;k<=50;k++)
				dp[i][j][k]=-2;
	
	LL best = -1,bestp=-1,bestpt=-1;;
	for(int i=0;i<m;i++)
		//for(LL a=39; a<=39;a++)
		for(LL a=0; a<=tk[i].b-tk[i].a; a++)
		{
			LL x = memo(i,a,n);
			if(x>best)
			{
				best = x;
				bestp = i;
				bestpt = a;
			}
		}
			
	if(best==-1)
	{
		printf("NO\n");
		return;
	}
	
	printf("YES\n");
	doit(bestp,bestpt,n);
		
}

bool input()
{
	s(n); s(m); s(k);
	LL a,b;
	int c;
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		tk.pb(task(a,b,c,i+1));
	}
	sort(all(tk));
	
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