#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
pair<int, int> q[222];

map<pair<int, int>, int> was;

int solve(int s, int x) {
	if (x == n) return 0;
	if (was.find(mp(s, x)) != was.end()) return was[mp(s, x)];

	int ret = 0;
	for (int i = x; i < n; i++) {
		int t = q[i].F - max(s, q[i].F - q[i].S);

		int u = q[i].F;
		int h = i;

		for (int j = x; j < n; j++) if (j != i) {
			if (q[j].F > u) break;
			h = max(h, j);
			if (q[j].F + q[j].S > u) {
				t += q[j].F + q[j].S - u;
				u = q[j].F + q[j].S;
			}
		}
		t += solve(u, h + 1);
		ret = max(ret, t);		
	}
	{
		int t = q[x].S;

		int u = q[x].F + q[x].S;
		int h = x;

		for (int j = x + 1; j < n; j++) {
			if (q[j].F > u) break;
			h = j;
			if (q[j].F + q[j].S > u) {
				t += q[j].F + q[j].S - u;
				u = q[j].F + q[j].S;
			}
		}
		t += solve(u, h + 1);
		ret = max(ret, t);		
	}
//	cout << s << " " << x << " " << ret << endl;
	was[mp(s, x)] = ret;
	return ret;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i].F >> q[i].S;
	sort(q, q + n);
	cout << solve(-2e8, 0) << endl;
	return 0;
}