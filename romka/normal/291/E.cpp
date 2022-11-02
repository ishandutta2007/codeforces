#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 100010;

vector<int> g[maxn];
vector<string> w[maxn];
char buf[300010];
int n, f[300010];
int k;
string pat;
int ans;

void go(int i) {
	int ck = k;
	forn(j, g[i].size()) {
		const string& s = w[i][j];
		forn(q, s.size()) {
			while (k > 0 && s[q] != pat[k]) k = f[k];
			k += s[q] == pat[k];
			if (k == (int)pat.size()) {
				k = f[k];
				ans++;
			}
		}
		go(g[i][j]);
		k = ck;
	}
}

int main() {
	scanf("%d", &n);
	int x;
	forn(i, n-1) {
		scanf("%d %s", &x, buf);
		g[x-1].pb(i + 1);
		w[x-1].pb(string(buf));
	}
	scanf("%s", buf);
	pat = string(buf);
	f[1] = 0;
	k = 0;
	forn(i, pat.size()) if (i) {
		while (k > 0 && pat[i] != pat[k]) k = f[k];
		f[i+1] = k += pat[i] == pat[k];
	}
	k = 0;
	go(0);
	printf("%d\n", ans);
	return 0;
}