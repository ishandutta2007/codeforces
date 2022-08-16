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
int h,m,k;
int h1,m1;
int h2,m2;
LL pw[21];
int hd,md;


int dchange(LL a,LL b)
{
	int cnt=0;
	while(a>0 || b>0)
	{
		if(a%10 != b%10) cnt++;
		a/=10;
		b/=10;
	}
	return cnt;
}

void preprocess()
{
	pw[0]=1;
	for(int i=1;i<=20;i++)
		pw[i] = 10*pw[i-1];
}


LL solve1(LL n,LL lo,LL hi)
{
	if(n>10) return 0;
	
	return (hi/pw[n-1] - lo/pw[n-1]);// - (hi/pw[n] - lo/pw[n]);
}

LL solveHour(LL h1,LL h2)
{
	LL ans = solve1(k,0,m-1) * (h2-h1+1);
	int x = dchange(m-1,0);
	//cout<<x<<endl;
	if(x<k)
	{
		ans += solve1(k-x,h1,h2);
		//cout<<(k-x)<<" "<<h1<<" "<<h2<<" "<<solve1(k-x,h1,h2)<<endl;
	}
	else
		ans += (h2-h1);
	return ans;
}
	

LL solve(LL h1,LL m1,LL h2,LL m2)
{
	hd=0;
	int temp=h;
	while(temp)
	{
		hd++;
		temp/=10;
	}
	temp=m;
	while(temp)
	{
		md++;
		temp/=10;
	}
	
	if(h2<h1 || (h2==h1 && m2<m1))
	{
		LL ans = solve(h1,m1,h-1,m-1) + solve(0,0,h2,m2);
		if(dchange(h-1,0)+dchange(m-1,0) >= k) ans++;
		//cout<<dchange(h-1,0)<<" "<<dchange(m-1,0)<<endl;
		return ans;
	}
	
	if(h1==h2)
		return solve1(k,m1,m2);
		
	if(h1+1==h2)
	{
		LL ans = solve1(k,m1,m-1) + solve1(k,0,m2);
		if(dchange(h1,h2)+dchange(m-1,0) >= k) ans++;
		return ans;
	}
	
	LL ans = solve1(k,m1,m-1) + solve1(k,0,m2) + solveHour(h1+1,h2-1);
	//cout<<solve1(k,m1,m-1)<<endl;
	//cout<<solve1(k,0,m2)<<endl;
	//cout<<solveHour(h1+1,h2-1)<<endl;
	if(dchange(h1,h1+1)+dchange(m-1,0) >= k) ans++;
	if(dchange(h2-1,h2)+dchange(m-1,0) >= k) ans++;
	return ans;
		
	
}

bool input()
{
	s(h); s(m); s(k);
	s(h1); s(m1);
	s(h2); s(m2);
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		cout<<solve(h1,m1,h2,m2)<<endl;
	}
}