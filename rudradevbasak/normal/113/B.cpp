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

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
char str[2005],beg[2005],end[2005];
int ls,lb,le;
LL hash[2005];
LL hbeg,hend;
vector<LL> all;
LL pow37[2005];


void preprocess()
{
	pow37[0]=1;
	for(int i=1;i<=2000;i++)
		pow37[i] = pow37[i-1]*37;
}

LL getHash(int a,int b)
{
	return hash[b] - hash[a]*pow37[b-a];
}

void display(vector<LL> a)
{
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<endl;
}

void solve()
{
	ls=strlen(str);
	lb=strlen(beg);
	le=strlen(end);
	
	hash[0]=0;
	for(int i=0;i<ls;i++)
		hash[i+1] = 37*hash[i] + (str[i]-'a'+1);
		
	hbeg=0;
	for(int i=0;i<lb;i++)
		hbeg = 37*hbeg + (beg[i]-'a'+1);
		
	hend=0;
	for(int i=0;i<le;i++)
		hend = 37*hend + (end[i]-'a'+1);	
	
	all.clear();
	for(int i=0;i<ls;i++)
		for(int j=i+max(lb,le);j<=ls;j++)
			if(getHash(i,i+lb)==hbeg && getHash(j-le,j)==hend)
				all.pb(getHash(i,j));

	DREP(all);
	
	printf("%d\n",all.size());
}

bool input()
{
	scanf("%s",str);
	scanf("%s",beg);
	scanf("%s",end);
	
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