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
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, m, d[N], p[N], r[N];
pt q[N];
vector<int> v[N];
long long fo;

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

void unite(int x, int y) {
	x = get(x);
	y = get(y);
	fo -= r[x] * 1ll * (r[x] - 1);
	fo -= r[y] * 1ll * (r[y] - 1);
	p[y] = x;
	r[x] += r[y];
	fo += r[x] * 1ll * (r[x] - 1);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%d", &d[i]);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < n; i++) q[i] = mp(d[i], i);
	sort(q, q + n);
	reverse(q, q + n);
	for (int i = 0; i < n; i++) p[i] = -1, r[i] = 1;
	fo = 0;
	long long ans = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		long long mem = fo;
		while (j < n && q[i].F == q[j].F) {
			p[q[j].S] = q[j].S;
			for (int k = 0; k < v[q[j].S].size(); k++) {
				int y = v[q[j].S][k];
				if (p[y] != -1 && get(p[y]) != get(q[j].S)) unite(p[y], q[j].S);
			}
			j++;
		}
//		cout << fo - mem << " " << q[i].F << endl;
		ans += (fo - mem) * q[i].F;
		i = j;
	}
	double ret = ans / 1./ n / (n - 1);
	printf("%.10f\n", ret);
	return 0;
}