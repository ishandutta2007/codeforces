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
#define N 211111

#define TASK "1"

using namespace std;

int n, m;
int e[N];

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a , b / 2);
	r = r * r % m;
	if (b % 2) r = r * a % m;
	return r;
}


long long rd() {
	long long r = 0;
	for (int i = 0; i < 60; i++) if (rand() % 2) r += pw(i);
	return r;
}

set<int> pos;

vector<int> bl;
int have[N];


void check(int d) {
			if (pos.find(d) == pos.end()) return;
			if (bl.size() > 0) {
				int c2 = 0;
				int la = e[0];
				for (int i = 0; i < bl.size(); i++) {
					int x = (bl[i] - d);
					if (x < 0) x += m;
					int h = lower_bound(e, e + n, x) - e;
					if (h < n && e[h] == x) c2++, la = x;
					if (c2 > 1) return;
				}
				cout << (la - ((n - 1) * 1ll * d) % m + m) % m << " " << d << endl;
				exit(0);
			}


			int cnt = 0;
			int la = e[0];

			for (int i = 0; i < n; i++) {
				int x = (e[i] + d);
				if (x >= m) x -= m;
				int h = lower_bound(e, e + n, x) - e;
				if (h < n && e[h] == x) {
				
				} else {
					cnt++;
					la = e[i];
				}
				if (cnt > 1) return;
			}
			cout << (la - ((n - 1) * 1ll * d) % m + m) % m << " " << d << endl;
			exit(0);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> e[i];
	sort(e, e + n);
	if (n == 1) {
		cout << e[0] << " " << 1 << endl;
		return 0;
	}
	int q = rd() % (n - 1) + 1;
	int qq = rd() % (q + 1);
//	for (int i = 1; i < n - 1; i++) if (e[i + 1] - e[i] < e[q + 1] - e[q]) q = i;

	for (int i = 1; i < n; i++) {
		int d = e[i] - e[0];
		pos.insert(d);
		pos.insert((m - d) % m);
	}

	int dist = e[q] - e[qq];
	int mdist = (m - dist) % m;

	if (m < n + n) {
		for (int i = 0; i < n; i++) have[e[i]] = 1;
		for (int i = 0; i < m; i++) if (!have[i]) bl.pb(i);	
	}


	for (int f = 1; f <= n - 1; f++) {
		check(dist * 1ll * pv(f, m - 2) % m);
		check(mdist * 1ll * pv(f, m - 2) % m);
	}
	cout << -1 << endl;



	return 0;
}