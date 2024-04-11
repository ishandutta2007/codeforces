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
#define N 1000111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
vector<int> v[N];
int have[N], s[N];

void add(int x, int g) {
	for (int o = 0; o < pw(v[x].size()); o++) {
		int t = 1;
		for (int i = 0; i < v[x].size(); i++) if (o & pw(i)) t *= v[x][i];
		s[t] += g;
	}
}

long long val(int x) {
	long long ret = 0;
	for (int o = 0; o < pw(v[x].size()); o++) {
		int t = 1;
		int cnt = 0;
		for (int i = 0; i < v[x].size(); i++) if (o & pw(i)) {
			t *= v[x][i];
			cnt ^= 1;
		}			

		if (cnt == 0) ret += s[t]; else ret -= s[t];
	}
	return ret;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);

		for (int j = 2; j * j <= x; j++) if (x % j == 0) {
			v[i].pb(j);
			while (x % j == 0) x /= j;
		}
		if (x > 1) v[i].pb(x);
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		x--;

		if (have[x]) {
			have[x] = 0;
			add(x, -1);
			ans -= val(x);
		} else {
			have[x] = 1;
			ans += val(x);
			add(x, 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}