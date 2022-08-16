/* AnilKishore ( RedAnt ) */

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
#define FORE(i,v) for(__typeof((v).begin()) i = (v).begin(); i!=(v).end(); i++)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 10005

map<string,PI> M;

PI get(string s)
{
	string r = ""; int a = 0, p = 0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='&') a++;
		else if(s[i]=='*') p++;
		else r+=s[i];
	if(M.count(r)==0 || M[r].F==-1) return MP(-1,-1);
	return MP(a+M[r].F,p+M[r].S);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif

	int n; cin>>n;

	M["void"] = MP(0,0);

	while(n--)
	{
		string op; cin>>op; 

		if(op=="typedef")
		{
			string from, to; cin>>from>>to;
			M[to] = get(from);
			if(M[to].F>M[to].S) M[to]=MP(-1,-1);
			//cout<<to<<" --> "<<"("<<M[to].F<<","<<M[to].S<<")"<<endl;
		}
		else
		{
			string q; cin>>q;
			PI res = get(q);
			if(res.F==-1 || res.F>res.S){ puts("errtype"); continue; }
			res.S-=res.F;
			cout<<"void";
			for(int i=0;i<res.S;i++) cout<<"*";
			cout<<endl;
		}
	}

	return 0;
}