using namespace std;

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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define SI ({int x;scanf("%d",&x);x;})
#define SET(v,x) memset(v,x,sizeof v)

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define TC REP(kase,SI)

#define SZ(v) int(v.size())
#define PB(x) push_back(x)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))

#define MP(x,y) make_pair(x,y)
#define F first
#define S second

#define MX 1005

int n,a[MX],f[MX],len;
vector<string> v[MX];
int pos[MX];
int s[MX];

void into2()
{
	for(int i=len;i>0;i--) s[i]=s[i-1];
	s[0]=0;
	len++;
}

bool plus1()
{
	int i=0;
	while(i<len && s[i]==1) i++;
	if(i==len)	return true;
	for(i=0;i<len;i++)
	{ 
		if(s[i]==0){ s[i]=1; break; }
		s[i]=0;
	}
	return false;
}

void store()
{
	string str;
	for(int i=0;i<len;i++) str+=char('0'+s[len-1-i]);
	v[len].PB(str); pos[len]++;
}

int main()
{
	n=SI;
	int i,j,k,left=n;

	for(i=0;i<n;i++) a[i]=SI, f[a[i]]++;
	bool ok = true;

	for(i=1;i<MX;i++)
	{
		into2();
		if(f[i]==0) continue;
		
		while(f[i]-- && ok)
		{
			store(); left--;
			bool of = plus1();
			//cout<<v[len][pos[len]-1]<<" "<<"of="<<of<<endl;
			if(of && left>0) ok=false;
		}

		if(left==0 || !ok) break;
	}

	if(!ok){ puts("NO"); } //printf("At len = %d , total done = %d\n",len,n-left); }
	else
	{
		puts("YES");
		for(i=0;i<n;i++) cout<<v[a[i]][--pos[a[i]]]<<endl;
	}

	return 0;
}