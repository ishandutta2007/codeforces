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

int a[N];
pair<int, int> q[N];
int s[N];
int n;

void put(int x, int d) {
	while (x < n) {
		s[x] += d;
		x = x | (x + 1);
	}
}

int get(int x) {
	int r = 0;
	while (x >= 0) {
		r += s[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) q[i] = mp(a[i] + i, i);
	sort(q, q + n);

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int id = q[i].S;
//		int val = a[id] + id + get(id);
		int val = a[id] + id - i;

//		put(id, -1);

		ans.pb(val);
	}
	int bad = 0;
	for (int i = 0; i < n; i++) if (ans[i] < 0 || (i < n - 1 && ans[i] > ans[i + 1])) bad = 1;
	if (bad) {
		puts(":(");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		printf("%d", ans[i]);
		if (i + 1 == n) puts(""); else putchar(' ');
	}
	return 0;
}