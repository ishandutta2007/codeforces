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

#define MX 1003

string name[MX];
int score[MX];

int main()
{
	map<string,int> m;
	int mx = -10000000;
	string winner;
	int n; cin>>n;
	REP(i,n)
	{
		cin>>name[i]>>score[i];
		m[name[i]]+=score[i];
	}

	EACH(it,m) mx = max(mx,it->second);

	map<string,int> m2;
	REP(i,n)
	{
		m2[name[i]]+=score[i];
		if(m[name[i]]==mx && m2[name[i]]>=mx)
		{
			cout<<name[i]<<endl;
			return 0;
		}
	}
	return 0;
}