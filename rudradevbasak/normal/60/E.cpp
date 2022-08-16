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
LL n,x,y,p;
LL a[1000005];
LL sum;


void preprocess()
{

}

LL pow3mod(LL n,LL p)
{
	LL ans=1;
	LL term=3;
	while(n>0)
	{
		if(n&1) ans=(ans*term)%p;
		n=n/2;
		term=(term*term)%p;
	}
	return ans;
}

pair<LL,LL> powfib(LL n,LL p)
{
	LL ansa=1,ansb=0,ansc=1;
	LL a=1,b=1,c=0;
	while(n>0)
	{
		if(n&1)
		{
			LL newa,newb,newc;
			newa=(a*ansa+b*ansb)%p;
			newb=(a*ansb+b*ansc)%p;
			newc=(b*ansb+c*ansc)%p;
			ansa=newa;
			ansb=newb;
			ansc=newc;
		}
		n=n/2;
			LL newa,newb,newc;
			newa=(a*a+b*b)%p;
			newb=(a*b+b*c)%p;
			newc=(b*b+c*c)%p;
			a=newa;
			b=newb;
			c=newc;
	}
	return make_pair(ansa,ansb);
}
	

void solve()
{
	if(n==1)
	{
		cout<<(a[0]%p)<<endl;
		return;
	}
	
	LL lo=a[0];
	LL hi=a[n-1];
	LL d=a[n-2];
	LL e=a[n-1];
	
	LL pow3n = pow3mod(x,p);
	LL newsum=(pow3n*sum)%p;
	LL factor;
	if(p%2==1)
	{
		factor = ((pow3n+p-1)*((p+1)/2))%p;
	}
	else
	{
		factor=((pow3mod(x,p+p)+p+p-1)/2)%p;
	}
	LL term=(factor*(lo+hi))%p;
	sum=(newsum+p-term)%p;
	
	//printf("pow3n = %lld,    newsum = %lld,   factor = %lld,    term = %lld,   sum=%lld\n",pow3n,newsum,factor,term,sum);
	
	
	pair<LL,LL> qq=powfib(x,p);
	hi = (d*qq.second + e*qq.first)%p;

	//printf("first = %lld,    second = %lld,    hi = %lld\n",qq.first,qq.second,hi);


	pow3n = pow3mod(y,p);
	newsum=(pow3n*sum)%p;
	if(p%2==1)
	{
		factor = ((pow3n+p-1)*((p+1)/2))%p;
	}
	else
	{
		factor=((pow3mod(y,p+p)+p+p-1)/2)%p;
	}
	term=(factor*(lo+hi))%p;
	sum=(newsum+p-term)%p;
	//printf("pow3n = %lld,    newsum = %lld,   factor = %lld,    term = %lld,   sum=%lld\n",pow3n,newsum,factor,term,sum);
	
	cout<<sum<<endl;
	
	
	
	
	
	
	
	
}

bool input()
{
	cin>>n>>x>>y>>p;
	sum=0;
	int x;
	for(int i=0;i<n;i++)
	{
		s(x);
		a[i]=x;
		sum=(sum+a[i])%p;
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