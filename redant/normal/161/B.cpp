/*AnilKishore*India*/

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

vector<PI> stool;
vector<PI> pencil;
vector<PI> ans[1111];

bool iss[MX];

int main()
{
	int n = SI, k = SI;
	REP(i,n)
	{
		int c = SI, t = SI;
		if(t==1) stool.PB(MP(c,i+1));
		else pencil.PB(MP(c,i+1));
		if(t==1) iss[i+1] = true;
	}
	SORT(stool);
	SORT(pencil);
	int si = SZ(stool)-1, pi = SZ(pencil)-1, sleft = SZ(stool), pleft = SZ(pencil);
	int ind = 0;
	for(int i=0;i<min(SZ(stool),k);i++) ans[ind++].PB(stool[si--]);
	if(ind==k)
	{
		while(si>=0) ans[k-1].PB(stool[si--]);
		while(pi>=0) ans[k-1].PB(pencil[pi--]);
	}
	else
	{
		while(ind<k) ans[ind++].PB(pencil[pi--]);
		while(pi>=0) ans[k-1].PB(pencil[pi--]);
	}
	double score = 0;
	REP(i,k)
	{
		int mn = (int)1e9;
		bool sss = false;
		EACH(it,ans[i])
		{
			int cst = it->first, ind = it->second;
			mn = min(mn,cst);
			if(iss[ind]) sss = true;
			score+=cst;
		}
		if(sss) score-=mn/2.;
	}
	printf("%.1lf\n",score);
	REP(i,k)
	{
		printf("%d",SZ(ans[i]));
		EACH(it,ans[i]) printf(" %d",it->second);
		puts("");
	}
	return 0;
}