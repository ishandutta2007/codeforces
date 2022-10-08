#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010

map<int, set<int> > A;
set<PII> B;
int a[N];
int b[N];
int n, xx, yy;

int main() {
	int _;
	cin >> _;
	while (_--)	 {
		cin >> n >> xx >> yy;
		A.clear();
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			a[i]--;
			A[a[i]].insert(i);
		}

		int nc = 0;
		while (A.find(nc) != A.end()) nc++;

		B.clear();
		for (auto p : A) {
			B.insert(mp(-(int)p.se.size(), p.fi));
		}

		memset(b, -1, sizeof b);

		for (int j = 0; j < xx; j ++) {
			PII p = *B.begin();
			B.erase(B.begin());
			B.insert(mp(p.fi+1, p.se));

			b[*A[p.se].begin()] = p.se;
			A[p.se].erase(A[p.se].begin());
		}

		int nn = n-xx;
		int ny = yy-xx;

		if ((nn - -B.begin()->fi)*2 < ny) {
			puts ("NO");
			continue;
		}

		vector<int> S;
		for (auto p : A)
			for (auto q : p.se) S.pb(q);
		int step;
		if (-B.begin()->fi*2 <= nn) step = nn/2;
		else step = nn - -B.begin()->fi;
		int my = 0;
		for (int i = 0; i < nn && my < ny; i ++)
			if (a[S[i]] != a[S[(i+step)%nn]]) {
				b[S[i]] = a[S[(i+step)%nn]];
				my++;
			}
				
		for (int i = 0; i < nn; i ++)
			if (b[S[i]] == -1) b[S[i]] = nc;
		
		puts ("YES");
		for (int i = 0; i < n; i ++)
			printf("%d%c", b[i]+1, i == n-1?'\n':' ');
	}
	return 0;
}