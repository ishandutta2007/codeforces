#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define s(n)	scanf("%d", &n);
#define sf(n)	scanf("%lf", &n);
#define ss(n)	scanf("%s", n);
#define all(v)	v.begin(),v.end()
#define FF		first
#define SS		second
#define tri(a,b,c)	mp(a,mp(b,c))
#define XX		first
#define YY		second.first
#define ZZ		second.second
#define fill(a,v)	memset(a,v,sizeof a)
#define INF		(int)1e9
#define	EPS		1e-9

#define debug(args...)	{dbg,args; cerr<<endl;}

struct debugger
{
	template <typename T>
	debugger & operator , (const T& v)
	{
		cerr << v << " ";
		return *this;
	}
} dbg;

void debugarr(int * a, int n)
{
	printf("[ ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("]\n");
}
	


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL>	VL;
typedef vector<PII> VII;
typedef vector<vector<int> > VVI;
typedef pair<int, pair<int,int> > TRI;


int testnum;
char str[105];
int n;


char get(int k)
{
	k%=n;
	if(k<0) k+=n;
	return str[k];
}

LL dp[105]; 

LL basic(int n)
{
	dp[1]=2;
	dp[2]=3;
	dp[3]=4;
	for(int i=4;i<=n;i++)
		dp[i] = dp[i-1]+dp[i-2];
	return dp[n];
}

LL fib[105];


LL solve(int n,char a,char b)
{
	int cnt=0;
	if(a=='B') cnt++;
	if(b=='A') cnt++;
	
	//debug(n,cnt);
	
	if(cnt==0) return fib[n-1];
	if(cnt==1) return fib[n+1];
	if(cnt==2) return fib[n+3];
}


char temp[105];
void solve()
{
	n=strlen(str);
	//debug("here");
	
	bool alt=true;
	bool same=true;
	for(int i=0;i<n;i++)
	{
		if(get(i) == get(i+1)) alt=false;
		if(get(i) != get(i+1)) same=false;
	}
	//debug(alt,same);
	if(same)
	{
		cout<<1<<endl;
		return;
	}
	
	//debug("aaa");
	
	for(int i=0;i<n;i++)
	{
		if(get(i)=='A' && get(i+1)=='A' && get(i+2)=='B' && get(i+3)=='B')
		{
			cout<<0<<endl;
			return;
		}
	}
	
	//debug("bbb");
	
	if(alt)
	{
		cout<<basic(n/2)<<endl;
		return;
	}
	
	int beg = -1;
	for(int i=0;i<n;i++)
	{
		if(get(i) == get(i+1))
			beg = (i+1)%n;
	}
	
	
	for(int i=0;i<n;i++)
		temp[i] = get(beg+i);
	for(int i=0;i<n;i++)
		str[i]=temp[i];
	//debug(str);
	
	LL ans = 1;
	for(int i=0; i<n; )
	{
		//debug("i",i);
		int j=i;
		while(!(get(j)=='A' && get(j+1)=='B')) j++;
		//debug(j);
		
		int k=j;
		while(get(k)=='A' && get(k+1)=='B') k+=2;
		//debug(k);
		
		if(j>=n) break;
		LL term = solve((k-j)/2, get(j-1), get(k));
		ans = ans * term;
		
		i=k;
	}
	
	for(int i=0;i<n;i++)
		if(get(i)=='B' && get(i+1)=='B' && get(i+2)=='A' && get(i+3)=='A')
			ans *= 2;
			
	cout<<ans<<endl;
}

void input()
{
	ss(str);
}

int main()
{
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<=100;i++)
		fib[i] = fib[i-1] + fib[i-2];
		
	int T=1;
	for(int testnum=1;testnum<=T;testnum++)
	{
		input();
		solve();
	}
}