/*
ID: AnilKishore ( RedAnt )
CONTEST: CodeForces#51
*/

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
#include <sstream>
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
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 111
LL r = 1000000000000000ll;
char op[3];

LL opr(LL a, LL b,char ch)
{
	return ch=='+' ? (a+b) : (a*b);
}

void go(vector<LL> v,int p)
{
	if(p==3){ r=min(r,v[0]); return; }

	int s = SZ(v);

	REP(i,s) FOR(j,i+1,s)
	{
		LL c = opr(v[i],v[j],op[p]);
		vector<LL> nv(1); nv[0]=c;
		REP(k,s) if(k!=i && k!=j) nv.PB(v[k]);
		go(nv,p+1);
	}
}

int main()
{
	vector<LL> v(4);
	REP(i,4) cin>>v[i];
	
	char ch;
	REP(i,3)
	{
		cin>>ch;
		op[i] = ch;
	}
	
	go(v,0);

	cout<<r<<endl;

	return 0;
}