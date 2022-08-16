
#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SL ({long long _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define MP make_pair
#define PB push_back
#define LL long long
#define _MAX 10000
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> PI; 
typedef pair <LL, PI> PLPI;
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

vector <pair <int, PI > > pt;
int k[100000 + 10];

bool compare(pair <int, PI > p, pair <int, PI > q) { return p.second.first < q.second.first; }
bool compare2(pair <int, PI > p, pair <int, PI > q) { return p.second.second < q.second.second; }

int dist(int i, int j)
{
	int d1 = (pt[i].second.first - pt[j].second.first), d2 = (pt[i].second.second - pt[j].second.second);
	return d1*d1 + d2*d2;
}

PI solve(int s, int e)
{
	if(e-s+1 <= 3)
	{
		int mini = INT_MAX;
		PI ans;
		for(int i = s;i<=e;++i)
			for(int j = i+1;j<=e;++j)
			{
				int d = dist(i,j);
				if(mini > d)
				{
					mini = d;
					ans = MP(i,j);
				}
			}
		return ans;
	}
	PI ans;
	int mid = (s+e)/2;
	PI lans = solve(s,mid), rans = solve(mid+1,e);
	int mini;
	int dl = dist(lans.first,lans.second), dr = dist(rans.first,rans.second);
	if(dl < dr) { mini = dl; ans = lans; }
	else { mini = dr; ans = rans; }
	vector <pair <int, PI> > v;
	int midx = pt[mid].second.first;
	int i = mid;
	while(i>=s && (midx - pt[i].second.first) <= mini) { v.PB(MP(i,pt[i].second)); --i; }
	i = mid+1;
	while(i<=e && (pt[i].second.first - midx) <= mini) { v.PB(MP(i,pt[i].second)); ++i; }
	sort(ALL(v),compare2);
	int up = 0, down = 0;
	int sz = SZ(v);
	while(up < sz)
	{
		while(down < sz-1 && v[down+1].second.second - v[up].second.second <= mini) ++down;
		for(int i = up; i<=down; ++i)
			for(int j = i+1; j<=down; ++j)
			{
				int d = dist(v[i].first,v[j].first);
				if(mini > d)
				{
					mini = d;
					ans = MP(v[i].first,v[j].first);
				}
			}
		++up;
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = SI;
	REP(i,n) { 
		int a = SI, b = SI;
		if(a >=0 && b >= 0) k[i] = 1;
		if(a >=0 && b < 0) k[i] = 3;
		if(a < 0 && b >= 0) k[i] = 2;
		if(a < 0 && b < 0) k[i] = 4;
		a = abs(a);
		b = abs(b);
		pt.PB(MP(i,MP(a,b)));
	}
	sort(ALL(pt),compare);
	PI ans = solve(0,n-1);
	int id1 = pt[ans.first].first, id2 = pt[ans.second].first;
	int k1 = k[id1], k2 = k[id2];
	k2 = 5 - k2;
	printf("%d %d %d %d",id1+1,k1,id2+1,k2);
	return 0;
}