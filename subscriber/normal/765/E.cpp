#include<bits/stdc++.h>
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
#define N 811111

#define TASK "1"

using namespace std;

int n;
set<int > v[N], ce[N];
int de[N];
int q1, q2;
int q[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].insert(y);
		v[y].insert(x);
	}
	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) if (v[i].size() == 1) {
		ce[i].insert(0);
		q[q1++] = i;
	}

	while (q1 != q2) {
		int x = q[q2++];
		if (de[x]) continue;

		if (v[x].size() == 0) break;

		de[x] = 1;

		assert(v[x].size() == 1);
		assert(ce[x].size() == 1);

		int len = (*ce[x].begin()) + 1;

		int pr = (*v[x].begin());

		v[pr].erase(x);
		ce[pr].insert(len);

		if (v[pr].size() + ce[pr].size() <= 2) {
			q[q1++] = pr;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) if (!de[i]) {
		for (auto it = ce[i].begin(); it != ce[i].end(); it++) ans += (*it);
		ans++;

		if (v[i].size() + ce[i].size() > 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	ans--;
	while(ans % 2 == 0) ans /= 2;
	cout << ans << endl;



	return 0;
}