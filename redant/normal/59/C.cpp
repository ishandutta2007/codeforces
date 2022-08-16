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
	int k = SI;
	char s[MX]; scanf(" %s",s);
	int n = strlen(s);
	int f[k+1]; SET(f,0);
	int nxt = k-1;

	for(int i=0;i<(n+1)/2;i++)
	{
		int j = n-1-i;
		if(s[i]=='?' && s[j]=='?') continue;

		if( s[i]!='?')
		{
			f[s[i]-'a']=1;
			if(s[j]!='?' && s[i]!=s[j]){ puts("IMPOSSIBLE"); return 0; }
			s[j]=s[i];
		}
		else
		{
			f[s[j]-'a']=1;
			if(s[i]!='?' && s[i]!=s[j]){ puts("IMPOSSIBLE"); return 0; }
			s[i]=s[j];
		}
	}

	for(int i=(n-1)/2;i>=0;i--)
	{
		int j = n-1-i;
		if(s[i]!='?') continue;
		while(nxt>=0 && f[nxt]) nxt--;
		if(nxt<0) s[i]=s[j]='a';
		else s[i]=s[j]='a'+nxt, f[s[i]-'a']=1;
	}

	for(int i=0;i<k;i++) if(!f[i]){ puts("IMPOSSIBLE"); return 0; }

	puts(s);

	return 0;
}