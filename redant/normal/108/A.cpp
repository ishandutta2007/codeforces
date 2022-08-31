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
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005

bool isPalin(int h,int m)
{
	char s[4];
	s[3]=m%10; s[2]=m/10;
	s[1]=h%10; s[0]=h/10;
	if(s[0]!=s[3] || s[1]!=s[2]) return false;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif

	int h,m;
	scanf("%d:%d",&h,&m);

	while(1)
	{
		m++; if(m==60) m=0, h++; if(h==24) h=0;
		if(isPalin(h,m)) break;
	}

	printf("%02d:%02d\n",h,m);

	return 0;
}