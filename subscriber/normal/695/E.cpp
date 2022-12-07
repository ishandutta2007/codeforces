#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pw(x) (1ll << (x))

using namespace std;

const int N = 222000;

int a[N], fr[N], fr2[N];
int ver[N];
int ans[N];

pair<pair<int, int>, pair<int, int> > q[N];

int curtime = 0;
vector<int> e;

int n, m;

void add(int x) {
//		for (int i = 0; i < 10; i++) cerr << fr[i] << " ";
//		cerr << endl;
		fr2[fr[a[x]]]--;
		fr[a[x]]++;
		fr2[fr[a[x]]]++;
		if (fr[a[x]] > 0 && fr2[fr[a[x]]] == 1) e.pb(fr[a[x]]);
}

void rem(int x) {
//		for (int i = 0; i < 10; i++) cerr << fr[i] << " ";
//		cerr << endl;
		fr2[fr[a[x]]]--;
		fr[a[x]]--;
		fr2[fr[a[x]]]++;
		if (fr[a[x]] > 0 && fr2[fr[a[x]]] == 1) e.pb(fr[a[x]]);
}

int main() {
	#ifdef home
		freopen("1.in", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		q[i] = mp(mp(x / 333, y), mp(x, i));
	}
	sort(q, q + m);
	int L = 0;
	int R = -1;
	for (int it = 0; it < m; it++) {
		int myL = q[it].S.F;
		int myR = q[it].F.S;
		while (R < myR) {
			R++;
			add(R);
		}
		while (L > myL) {
			L--;
			add(L);
		}
		while (R > myR) {
			rem(R);
			R--;
		}
		while (L < myL) {
			rem(L);
			L++;
		}
//		cout << q[it].S.S << endl;
//		cout << "e.size() = " << e.size() << endl;
		curtime++;
		vector<int> ee;
		for (int j = 0; j < e.size(); j++) {
			if (fr2[e[j]] == 0 || ver[e[j]] == curtime) continue;
			ee.pb(e[j]);
			ver[e[j]] = curtime;
		}
//		cout << "ee.size() = " << ee.size() << endl;
//		for (int i = 1; i < 15; i++) cout << fr2[i] << " ";
//		cout << endl;
		e = ee;
		sort(ee.begin(), ee.end());
		vector<pair<int, int> > A[2];
		for (int i = 0; i < ee.size(); i++) A[0].pb(mp(ee[i], fr2[ee[i]]));

		int u[2];
		u[0] = u[1] = 0;

//		for (int i = 0; i < A[0].size(); i++) cout << '(' << A[0][i].F << " " << A[0][i].S << ')' << " ";
//		cout << endl;
//		continue;

		int res = 0;
		int cnt = 0;
		for (int i = 0; i < A[0].size(); i++) cnt += A[0][i].S;
		while (cnt > 1) {
			for (int i = 0; i < 2; i++) if (u[i] < A[i].size() && A[i][u[i]].S == 0) u[i]++;
			if (u[0] < A[0].size() && u[1] < A[1].size() && A[0][u[0]].F == A[1][u[1]].F) {
				A[1][u[1]].S += A[0][u[0]].S;
				A[0][u[0]].S = 0;
				continue;
			}

			int mv = 0;
			if (u[0] == A[0].size() || (u[1] < A[1].size() && A[1][u[1]].F < A[0][u[0]].F)) mv = 1;

			if (A[mv][u[mv]].S > 1) {
				int t = (A[mv][u[mv]].S >> 1);

//				cout << mv << " " << A[mv][u[mv]].F << " " << t << endl;

				res += A[mv][u[mv]].F * t * 2;
				A[mv][u[mv]].S -= t * 2;
				A[1].pb(mp(A[mv][u[mv]].F * 2, t));
				cnt -= t;
				continue;
			}
			int we = A[mv][u[mv]].F;
//			cout << "old " << mv << endl;
			u[mv]++;
			mv = 0;
			if (u[0] == A[0].size() || (u[1] < A[1].size() && A[1][u[1]].F < A[0][u[0]].F)) mv = 1;

//			cout << we << " " << mv << " " << A[mv][u[mv]].F << " " << A[mv][u[mv]].S << endl;

			res += we + A[mv][u[mv]].F;
			A[mv][u[mv]].S--;
			A[1].pb(mp(we + A[mv][u[mv]].F, 1));
			cnt--;
		}
		ans[q[it].S.S] = res;
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);

	return 0;
}