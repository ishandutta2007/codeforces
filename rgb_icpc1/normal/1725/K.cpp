#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
#define X first
#define Y second
using LL = long long;
using PI = pair<int, int>;
using PP = pair<PI, int>;
using VP = vector<PP>;
using VI = vector<int>;
const int N = 400005;
const int INF = 1000000005;

void out(VP &v) { for (PP p : v) cerr << p.X.X << ' ' << p.X.Y << ' ' << p.Y << endl; }

int find(int u, VP &v) {
	int ps = upper_bound(v.begin(), v.end(), PP(PI(u, INF), INF)) - v.begin();
	ps --;
//	assert(v[ps].X.Y >= u);
	if (v[ps].Y == -1) return u;
	return v[ps].Y;
}

void merge(VP &v1, VP &v2, VP &v3) {
	int sz1 = v1.size(), sz2 = v2.size();
//	if (sz1 > 1 && sz2 > 1) {
//		cout << "start" << endl;
//		out(v1);
//		out(v2);
//	}
	VP v4;
	v4.clear();
	for (int i = 0, j = 0; i < sz1; i ++) {
		if (v1[i].Y == -1) {
			while (v2[j].X.Y < v1[i].X.X) j ++;
			int en = min(v1[i].X.Y, v2[j].X.Y);
//			assert(v1[i].X.X <= v2[j].X.Y);
			v4.pb(PP(PI(v1[i].X.X, en), v2[j].Y));
			while (en < v1[i].X.Y) {
				int st = en + 1;
				j ++;
				en = min(v1[i].X.Y, v2[j].X.Y);
				v4.pb(PP(PI(st, en), v2[j].Y));
//				if (sz1 > 1 && sz2 > 1) {
//					cerr << st << '-' << en << '-' << v2[j].Y << endl;
//				}
			}
		} else {
			while (v2[j].X.Y < v1[i].Y) j ++;
			v4.pb(PP(v1[i].X, (v2[j].Y == -1) ? v1[i].Y : v2[j].Y));
		}
	}
	int sz = v4.size();
	v3.clear();
	for (int i = 0; i < sz; i ++) {
		if (i && v3.back().Y == v4[i].Y) {
			v3.back().X.Y = v4[i].X.Y;
			continue;
		}
		v3.pb(v4[i]);
	}
//	if (sz1 > 1 &&sz2 > 1) {
//		out(v3);
//		cout << "end" << endl;
//	}
	v3 = v4;
}

VP v[N * 4];
int wtn;
int n, A[N];
int q;
int qid[N], q1[N], q2[N];
int lst[N];

void build() {
	int i;
	for (wtn = 1; wtn < q; wtn *= 2);
	for (i = 0; i < q; i ++) {
		v[wtn + i].clear();
		if (qid[i] == 3) {
			v[wtn + i].pb(PP(PI(1, q1[i] - 1), -1));
			int md = (q1[i] + q2[i]) / 2;
			v[wtn + i].pb(PP(PI(q1[i], md), q1[i] - 1));
			v[wtn + i].pb(PP(PI(md + 1, q2[i]), q2[i] + 1));
			v[wtn + i].pb(PP(PI(q2[i] + 1, INF), -1));
		} else v[wtn + i].pb(PP(PI(1, INF), -1));
	}
	for (i = q; i < wtn; i ++) {
		v[wtn + i].clear();
		v[wtn + i].pb(PP(PI(1, INF), -1));
	}
	for (i = wtn - 1; i > 0; i --) merge(v[i * 2], v[i * 2 + 1], v[i]);
}

int get(int st, int en, int u) {
//	cerr << "-------------------" << endl;
//	cerr << st << " " << en << ' ' << u << endl;
	VI V1, V2;
	V1.clear(), V1.clear();
	st += wtn, en += wtn;
	while (st < en) {
		if (st & 1) V1.pb(st);
		if (en & 1) V2.pb(en - 1);
		st = (st + 1) / 2;
		en /= 2;
	}
	reverse(V2.begin(), V2.end());
	for (int vv : V1) {
		u = find(u, v[vv]);
	}
	for (int vv : V2) {
		u = find(u, v[vv]);
	}
	return u;
//	out(rlt1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> A[i];
	cin >> q;
	for (int i = 0; i < q; i ++) {
		cin >> qid[i];
		if (qid[i] == 2) cin >> q1[i];
		else cin >> q1[i] >> q2[i];
	}
	build();
	for (int i = 0; i < q; i ++) {
		if (qid[i] == 1) {
			lst[q1[i]] = i;
			A[q1[i]] = q2[i];
		}
		if (qid[i] == 2) {
//			cerr << lst[q1[i]] << ' ' << i << endl;
			cout << get(lst[q1[i]], i, A[q1[i]]) << endl;
		}
	}
	
	return 0;
}