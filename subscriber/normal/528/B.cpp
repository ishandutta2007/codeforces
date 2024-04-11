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
#define N 411111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
pair<int, int> q[N], w[N];
int s[N], f[N], u[N];

int fin(int x) {
	int r = 0;
	while (x > 0) {
		r = max(r, s[x]);
		x &= x - 1;
	}
	return r;
}

void add(int x, int v) {
	x++;
	while (x <= n) {
		s[x] = max(s[x], v);
		x = x + x - (x & (x - 1));
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i <n; i++) scanf("%d%d", &q[i].F, &q[i].S);
	sort(q, q + n);

	for (int i = 0; i < n; i++) w[i] = mp(q[i].F + q[i].S, i);
	sort(w, w + n);

	for (int i = 0; i < n; i++) u[w[i].S] = i;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val = q[i].F - q[i].S;
		int x = upper_bound(w, w + n, mp(val, 1000000)) - w;

		f[i] = fin(x) + 1;
		ans = max(ans, f[i]);
		add(u[i], f[i]);
	}
	cout << ans << endl;

	return 0;
}