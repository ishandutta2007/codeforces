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

int n, q;
int st[2];

int ans[2000222];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> q;

	vector<int> a[2];

	for (int i = 0; i < n; i++) a[i & 1].pb(i);

	st[0] = st[1] = 0;

	int x = 0;
	int y = 1;

	for (int i = 0; i < q; i++) {
		int type;
		scanf("%d", &type);
		if (type == 2) {
			swap(x, y);
		} else {
			int t;
			scanf("%d", &t);
			t = -t;

			t = (t + n) % n;

			if (t == 0) continue;
			st[x] = (st[x] + (t + 1) / 2) % (n / 2);
			st[y] = (st[y] + (t) / 2) % (n / 2);
			if (t % 2) swap(x, y);
		}
	}
	vector<int> p;
	for (int i = 0; i < n / 2; i++) {
		p.pb(a[x][(st[x] + i) % (n / 2)]);
		p.pb(a[y][(st[y] + i) % (n / 2)]);
	}
//	for (int i = 0; i < n; i++) cout << p[i] << " ";
//	cout << endl;
//	for (int i = 0; i < n; i++) ans[p[i]] = i;
	for (int i = 0; i < n; i++) ans[i] = p[i];

	for (int i = 0; i < n; i++) {
		printf("%d", ans[i] + 1);
		if (i + 1 == n) puts(""); else putchar(' ');
	}


	return 0;
}