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
int n;
const int maxn=100005;
int a[maxn];
VVI cycles;
VVI bs;
VVI cs;
VVI b;
VVI c;
VVI b2;
VVI c2;
VVI b3;
VVI b33;
VVI c3;
VVI c33;
VVI b4;
VVI c4;
bool done[maxn];



void preprocess()
{

}

void solve()
{
	fill(done,false);
	for(int i=0;i<n;i++)
	{
		if(done[i]) continue;
		VI cur;
		int j=i;
		while(!done[j])
		{
			cur.pb(j);
			done[j]=true;
			j=a[j];
		}
		cycles.pb(cur);
	}
	
	for(int i=0;i<cycles.size();i++)
	{
		
		int rem=cycles[i].size();
		if(rem==1) continue;
		if(rem<=5)
		{
			
			VI cb;
			VI cc;
			for(int j=0;j<rem;j++)
			{
				cb.pb(cycles[i][j]);
				cc.pb(cycles[i][(j+1)%rem]);
			}
			bs.pb(cb);
			cs.pb(cc);
		}
		else
		{
			VI cb;
			VI cc;
			for(int j=rem-5;j<rem;j++)
			{
				cb.pb(cycles[i][j]);
				cc.pb(cycles[i][(j-rem+6)%5+(rem-5)]);
			}
			bs.pb(cb);
			cs.pb(cc);
			
			
			cycles[i].resize(rem-4);
			i--;
		}
	}
	

	for(int i=0;i<bs.size();i++)
	{
		int len=bs[i].size();
		if(len==2)
		{
			b2.pb(bs[i]);
			c2.pb(cs[i]);
		}
		else if(len==3)
		{
			b33.pb(bs[i]);
			c33.pb(cs[i]);
		}
		else
		{
			b.pb(bs[i]);
			c.pb(cs[i]);
		}
	}
	
	int n2=b2.size();
	int n3=b33.size();
	int nmin=min(n2,n3);
	
	
	if(true)
	{
		for(int i=0;i<n3;i++)
		{
			int j=i-(n2-1);
			if(j%3 == 0 && j>0)
			{
				VI a1,a2,a3,a4;
				a1.pb(b33[i][0]); a1.pb(b33[i][1]);
				a2.pb(c33[i][0]); a2.pb(c33[i][2]);
				b2.pb(a1);
				c2.pb(a2);
				
				a3.pb(b33[i][0]); a3.pb(b33[i][2]);
				a4.pb(c33[i][1]); a4.pb(c33[i][2]);
				b2.pb(a3);
				c2.pb(a4);
			}
			else
			{
				b3.pb(b33[i]);
				c3.pb(c33[i]);
			}
		}
	}
	
	n2=b2.size();
	n3=b3.size();
	nmin=min(n2,n3);
	
	for(int i=0;i<nmin;i++)
	{
		VI tb;
		VI tc;
		tb.pb(b2[i][0]); tb.pb(b2[i][1]); tb.pb(b3[i][0]); tb.pb(b3[i][1]); tb.pb(b3[i][2]);
		tc.pb(c2[i][0]); tc.pb(c2[i][1]); tc.pb(c3[i][0]); tc.pb(c3[i][1]); tc.pb(c3[i][2]);
		b.pb(tb);
		c.pb(tc);
	}
	
	if(n2<n3)
	for(int i=nmin;i<n3;i++)
	{
		VI tb;
		VI tc;
		tb.pb(b3[i][0]); tb.pb(b3[i][1]); tb.pb(b3[i][2]);
		tc.pb(c3[i][0]); tc.pb(c3[i][1]); tc.pb(c3[i][2]);
		b.pb(tb);
		c.pb(tc);
	}
	
	if(n3<n2)
	for(int i=nmin;i<n2;i++)
	{
		VI tb;
		VI tc;
		tb.pb(b2[i][0]); tb.pb(b2[i][1]); 
		tc.pb(c2[i][0]); tc.pb(c2[i][1]); 
		i++;
		if(i<n2)
		{
			tb.pb(b2[i][0]); tb.pb(b2[i][1]); 
			tc.pb(c2[i][0]); tc.pb(c2[i][1]); 
		}
		b.pb(tb);
		c.pb(tc);
	}
	
	
	
	printf("%d\n",b.size());
	for(int i=0;i<b.size();i++)
	{
		printf("%d\n",b[i].size());
		
		for(int j=0;j<b[i].size();j++)
			printf("%d ",b[i][j]+1);
		printf("\n");
		
		for(int j=0;j<b[i].size();j++)
			printf("%d ",c[i][j]+1);
		printf("\n");
	}
			
		
		
}

bool input()
{
	s(n);
	for(int i=0;i<n;i++)
	{
		s(a[i]);
		a[i]--;
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