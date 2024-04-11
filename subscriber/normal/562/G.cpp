#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<ctime>
#include<cassert>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define N 1222000

using namespace std;

int n;
int a[N], b[N], c[N];
int used[N];
vector<int> v[N];

vector<int> ans;
int h[N];

void make(int e) {
	ans.pb(e);
	used[e] = 1;

	int g = a[e];
	for (int i = 0; i < v[g].size(); i++) if (!used[v[g][i]]) {
		make(v[g][i]);
		break;
	}
}

int main() {
	#ifdef home
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n * 4; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]--;
		b[i]--;
		c[i]--;
		v[b[i]].pb(i);
		v[c[i]].pb(i);
	}
//	for (int i = 0; i < n; i++) h[i] = 8;
	for (int i = 0; i < n * 4; i++) if (!used[i]) make(i);
	reverse(ans.begin(), ans.end());
	//check
	for (int i = 0; i < n; i++) h[i] = 4;
	for (int i = 0; i < ans.size(); i++) {
		h[a[ans[i]]]--;
		h[b[ans[i]]]--;
		h[c[ans[i]]]--;
		if (h[b[ans[i]]] > 9 || h[c[ans[i]]] > 9) {
			assert(false);
		}

	}
//	cerr << "OK " << time(0) << endl;

	//endcheck


	puts("YES");
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i] + 1);
		if (i + 1 == ans.size()) puts(""); else putchar(' ');
	}
	return 0;
}