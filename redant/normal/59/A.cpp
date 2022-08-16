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

#define MX 111

int main()
{
	char s[MX]; gets(s);
	int uc=0,lc=0;
	for(int i=0;i<strlen(s);i++)
		if(s[i]>='a'&&s[i]<='z') lc++;
		else uc++;
	if(uc>lc){ for(int i=0;i<strlen(s);i++) if(s[i]>='a'&&s[i]<='z') s[i]^=32; }
	else for(int i=0;i<strlen(s);i++) if(s[i]>='A'&&s[i]<='Z') s[i]^=32;
	puts(s);
	return 0;
}