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
#define s 1000111
using namespace std;
typedef pair<int,int> pt;

int n, m;
int ss[s + s];
int ans[s + s];
int out[s];
int used[s];

void add(int x, int v) {
	while (x < s + s) {
		ss[x] += v;
		x = x + x - (x & (x - 1));
	}
}

int fin(int x) {
	int r = 0;
	while (x > 0) {
		r += ss[x];
		x &= x - 1;
	}
	return r;
}

int main(){

//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		add(s + i, 1);
		ans[s + i] = -1;
	}
	int fr = s - 1;
	for (int i = 0; i < m; i++) {
		int v, x;
		scanf("%d %d", &v, &x);
		int l = 0;
		int r = s + s;
		while (l < r) {
			int mid = (l + r) / 2;
			if (fin(mid) < x) l = mid + 1; else r = mid;
		}
		if (ans[l] == -1) {
			if (used[v]) {
				puts("-1");
				return 0;
			}
			out[l - s] = v;
			used[v] = 1;
		} else
		if (ans[l] != v) {
			puts("-1");
			return 0;
		}
		add(l, -1);
		add(fr, 1);
		ans[fr] = v;
		fr--;
	}
	vector<int> g;
	for (int i = 1; i <= n; i++) if (!used[i]) g.pb(i);
	for (int i = n - 1; i >= 0; i--) if (!out[i]) {
		out[i] = g.back();
		g.pop_back();
	}
	for (int i = 0; i < n - 1; i++) printf("%d ", out[i]);
	cout << out[n - 1] << endl;
	return 0;
}