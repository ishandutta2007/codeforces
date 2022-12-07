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

int n, m;
int p[N], d[N];

int get(int x) {
	if (x == p[x]) return x;

	int t = get(p[x]);

	d[x] ^= d[p[x]];
	p[x] = t;
	return t;	
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		d[i] = 0;
	}
	int k = n - 1;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		if (get(x) != get(y)) {
			k--;
			int dd = 1  ^z;
			dd ^= d[x];
			dd ^= d[y];

			d[p[x]] = dd;
			p[p[x]] = p[y];
		} else {
			int dd = d[x] ^ d[y];
			dd ^= (1 ^ z);
			if (dd) {
				puts("0");
				return 0;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < k; i++) ans = (ans *  2) % M;
	cout << ans << endl;
	return 0;
}