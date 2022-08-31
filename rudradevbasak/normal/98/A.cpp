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
char s[20];
int freq[26];
VI f;


void preprocess()
{

}

int solve()
{
	fill(freq,0);
	for(int i=0;i<6;i++)
		freq[ s[i]-'A' ] ++;
		f.clear();
	for(int i=0;i<26;i++)
		if(freq[i]>0)
			f.pb(freq[i]);
	sort(f.begin(),f.end());
	if(f.size()==1) return 1;
	if(f.size()==2)
	{
		if(f[0]==1) return 1;
		if(f[0]==2) return 2;
		if(f[0]==3) return 2;
	}
	if(f.size()==3)
	{
		if(f[0]==1)
		{
			if(f[1]==1) return 2;
			if(f[1]==2) return 3;
		}
		if(f[0]==2) return 6; //??
	}
	if(f.size()==4)
	{
		if(f[3]==3) return 5;
		if(f[3]==2) return 8;
	}
	if(f.size()==5) return 15;
	if(f.size()==6) return 30;
		
		
}

bool input()
{
	scanf("%s",s);
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		printf("%d\n",solve());
	}
}