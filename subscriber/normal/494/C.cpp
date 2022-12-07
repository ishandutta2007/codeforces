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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int ma = 0;
int L, R;

int a[N];
pair<pt, double> e[5555];
int lv[5555];
bool was[5555][10111];
float mem[5005][10111];

vector<int> v[5555];

map<int, double> ls;

int q;



double rec(int x, int val) {
	if (was[x][val - L]) return mem[x][val - L];
	if (v[x].size() == 0) {
		if (lv[x] + 1 < val) return 1;
		if (lv[x] + 1 == val) return 1 - e[x].S;
		return 0;
	}

	double p1 = 1;
	double p2 = 1;
	if (lv[x] >= val) p1 = 0;
	if (lv[x] + 1 >= val) p2 = 0;

	for (int i = 0; i < v[x].size(); i++) {
		p1 *= rec(v[x][i], val);
		p2 *= rec(v[x][i], val - 1);
	}
	double ret = p2 * e[x].S + p1 * (1 - e[x].S);

//	cout << e[x].F.F << " " << e[x].F.S << " " << val << endl;
//	cout << ret << endl;
	was[x][val - L] = 1;
	return mem[x][val - L] = ret;
	
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ma = max(ma, a[i]);
	}		
	for (int i = 0; i< q; i++) {
		cin >> e[i].F.F >> e[i].F.S >> e[i].S;
		e[i].F.F--;
		e[i].F.S--;
	}
	for (int i = 0; i < q; i++) for (int j = i + 1; j < q; j++) if (e[i].F.S - e[i].F.F < e[j].F.S - e[j].F.F) swap(e[i], e[j]);
//	sort(e, e + q);

	int root = q;
	for (int i = 0; i < q; i++) {
		int d = 1e9;
		int h = -1;
		for (int j = 0; j < i; j++) if (e[j].F.F <= e[i].F.F && e[j].F.S >= e[i].F.S && e[j].F.S - e[j].F.F <= d) {
			d = e[j].F.S - e[j].F.F;
			h = j;
		}
		if (h == -1) h = root;
		v[h].pb(i);
	}
	for (int i = 0; i < q; i++) {
		lv[i] = 0;
		for (int j = e[i].F.F; j <= e[i].F.S; j++) lv[i] = max(lv[i], a[j]);
		
	}

	L = ma - q;
	R = ma + q;

	ls[ma] = 0;
	for (int i = ma + 1; i <= ma + q + 1; i++) {
		double g = 1;
		for (int j = 0; j < v[root].size(); j++) g *= rec(v[root][j], i);
//		cout << i << " " << g << endl;
		ls[i] = g;		
	}
	double ans = 0;
	for (int i = ma; i <= ma + q; i++) {
		double v = ls[i + 1] - ls[i];
		ans += i * v; 
	}
	printf("%.15lf\n", ans);
	return 0;
}