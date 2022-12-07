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

int n;
int a[N];

int vb(int i) {
		if (i < 0 || i == n - 1) return 0;
		if (a[i] == -1 || a[i + 1] == -1) return 0;
		if (i % 2 == 0) {
			return a[i] >= a[i + 1];
                } else {
                	return a[i] <= a[i + 1];
                }
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> e;
	
	int errs = 0;
	for (int i = 0; i < n - 1; i++) {
                if (vb(i)) {
                	errs++;
                	e.pb(i);
                	e.pb(i + 1);
                }
	}
	sort(e.begin(), e.end());
	e.resize(unique(e.begin(), e.end()) - e.begin());

	if (e.size() > 6) {
		puts("0");
		return 0;
	}

	vector<pair<int, int> > ans;


	for (int i = 0; i < e.size(); i++) for (int y = 0; y < n; y++) {
		int x = e[i];
		if (x == y) continue;

		int me = errs;

		int mx = a[x];
		int my = a[y];

		me -= vb(x);
		me -= vb(x - 1);

		a[x] = -1;

		me -= vb(y);
		me -= vb(y - 1);

		a[y] = mx;

		me += vb(y);
		me += vb(y - 1);

		a[x] = my;

		me += vb(x);
		me += vb(x - 1);

		if (me == 0) ans.pb(mp(min(x, y), max(x, y)));

		a[x] = mx;
		a[y] = my;
	}

	sort(ans.begin(), ans.end());

	cout << unique(ans.begin(), ans.end()) - ans.begin() << endl;
	

	return 0;
}