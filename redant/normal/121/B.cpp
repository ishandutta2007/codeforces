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

char s[MX];

int main()
{
	queue<int> odd, even;
	
	int n = SI, k = SI;
	
	scanf(" %s",s+1);
	
	FOR(i,1,n)
	{
		if(s[i]=='4' && s[i+1]=='7')
			if(i&1) odd.push(i); else even.push(i);
	}

	while(k--)
	{
		int ind = MX;
		
		if(SZ(odd))  ind=min(ind,odd.front());
		if(SZ(even)) ind=min(ind,even.front());
		
		if(ind==MX) break;
		
		if(odd.front()==ind)
		{
			s[ind+1]='4';
			if(ind+2<=n && s[ind+2]=='7')
			{
				if(k&1) s[ind+1]='7';
				break;
			}
			odd.pop();
		}
		else
		{
			s[ind]='7';
			if(ind>1 && s[ind-1]=='4')
			{
				if(k&1) s[ind]='4';
				break;
			}
			even.pop();
		}	
		//puts(s+1);
	}
	puts(s+1);
	return 0;
}