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

#define MX 100010

int n,m;
map<string,int> mp;
string szs[] = {"S","M","L","XL","XXL"};
int lft[5];

string get(int x)
{
	if(lft[x]>0){ lft[x]--; return szs[x]; }
	for(int i=1;;i++)
	{
		int y = x+i;
		if(y>=0 && y<5 && lft[y]>0){ lft[y]--; return szs[y]; }
		y=x-i;
		if(y>=0 && y<5 && lft[y]>0){ lft[y]--; return szs[y]; }
	}
}

int main()
{
	int i,j,K,t,r;
	
	for(i=0;i<5;i++)
	{
		mp[szs[i]]=i;
		lft[i] = SI;
	}

	K=SI;
	while(K--)
	{
		string s; cin>>s;
		cout<<get(mp[s])<<endl;
	}

	return 0;
}