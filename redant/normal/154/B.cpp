/* RedAnt */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005
VI primes[MX];
bool isP[MX];
int who[MX];
bool thr[MX];

void pre()
{
	memset(isP,true,sizeof isP);
	for(int i=2;i<MX;i+=2) primes[i].PB(2);
	for(int i=3;i<MX;i+=2) if(isP[i])
	{
		for(int j=i;j<MX;j+=i)
		{
			isP[j] = false;
			primes[j].PB(i);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif

	pre();
	
	int n = SI, m = SI;
	
	while(m--)
	{
		char ch; int x;
		scanf(" %c %d",&ch,&x);
		if(ch=='+')
		{
			if(thr[x]) puts("Already on");
			else
			{
				int y = 0;
				EACH(it,primes[x]) if(who[*it]>0) y = who[*it];
				if(y) printf("Conflict with %d\n",y);
				else
				{
					EACH(it,primes[x]) who[*it] = x;
					puts("Success");
					thr[x] = true;
				}
			}
		}
		else
		{
			if(!thr[x]) puts("Already off");
			else
			{
				EACH(it,primes[x]) who[*it] = 0;
				thr[x] = false;
				puts("Success");
			}
		}
	}
		
	return 0;
}