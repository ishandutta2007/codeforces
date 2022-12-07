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
#define N 511111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int maxa = 10000000;

int n, k;
int a[N];

int f[11000111];
int cnt[11000111];
int si[11000111];
int pp[N];

int p[22];
int d[N];
map<int, int> mem;


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= maxa; i++) if (!f[i]) {
		int j = i + i;
		while (j <= maxa) {
			if (!f[j]) f[j] = i;
			j += i;
		}
	}
	pp[0] = 1;
	for (int i = 1; i <= n; i++) pp[i] = (pp[i - 1] * 2) % M;

	
	for (int i = 0; i < n; i++) {
		k = 0;
		int x = a[i];		
		while (x > 1 && f[x]) {
			if (k == 0 || p[k - 1] != f[x]) {
				p[k++] = f[x];
			}
			x /= f[x];
		}
		if (x > 1) {
			if (k == 0 || p[k - 1] != x) p[k++] = x;
		}

		d[0] = 1;
		si[1] = 1;
		for (int o = 1; o < pw(k); o++) for (int i = 0; i < k; i++) if (o & pw(i)) {
			d[o] = d[o ^ pw(i)] * p[i];
			si[d[o]] = si[d[o ^ pw(i)]] * (-1);
		}
		for (int o = 0; o < pw(k); o++) cnt[d[o]]++;
	}
	int all = 0;
	for (int o = 2; o <= maxa; o++) {
		all = (all + (pp[cnt[o]] - 1) *1ll* (-si[o]) + 5ll * M) % M;
	}


	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (mem.find(a[i]) != mem.end()) {
			ans = (ans + mem[a[i]]) % M;
			continue;
		}
		k = 0;
		int x = a[i];		
		while (x > 1 && f[x]) {
			if (k == 0 || p[k - 1] != f[x]) {
				p[k++] = f[x];
			}
			x /= f[x];
		}
		if (x > 1) {
			if (k == 0 || p[k - 1] != x) p[k++] = x;
		}

		d[0] = 1;
		for (int o = 1; o < pw(k); o++) for (int i = 0; i < k; i++) if (o & pw(i)) {
			d[o] = d[o ^ pw(i)] * p[i];
		}
		for (int oo = 1; oo < pw(k); oo++) {
			int o = d[oo];
			all = (all - (pp[cnt[o]] - 1) *1ll* (-si[o]) + 5ll * M) % M;

			cnt[d[oo]]--;

			all = (all + (pp[cnt[o]] - 1) *1ll* (-si[o]) + 5ll * M) % M;

		}

		long long cur = 0;
		for (int o = 1; o < pw(k); o++) {
			int t = pp[cnt[d[o]]] - 1;
			if (t < 0) t += M;
			if (__builtin_popcount(o) & 1) {
				cur += t;
			} else cur -= t;
		}


		cur = (cur + M * 1ll * M) % M;
		cur = (all - cur + M) % M;
		mem[a[i]] = cur;
		ans = (ans + cur) % M;

		for (int oo = 1; oo < pw(k); oo++) {
			int o = d[oo];
			all = (all - (pp[cnt[o]] - 1) *1ll* (-si[o]) + 5ll * M) % M;

			cnt[d[oo]]++;

			all = (all + (pp[cnt[o]] - 1) *1ll* (-si[o]) + 5ll * M) % M;

		}

	}
	cout << ans << endl;




	return 0;
}