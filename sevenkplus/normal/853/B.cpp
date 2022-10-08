#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (__typeof((c).begin()) i=((c).begin()); i!=((c).end()); i++)

#define INF 1000000000000000000LL
#define N 100010

int n, m, k;
ll S, T;
// departure min
multiset<int> A[N];
int px[N], py[N], pz[N], pw[N], p1[N], L1, p2[N], L2;
bool v[N]; int co[N];
int nw;

int cmp(int x, int y) {
	return px[x] < px[y];
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i ++) {
		scanf("%d%d%d%d", px+i, py+i, pz+i, pw+i);
		if (py[i] == 0) {
			A[pz[i]].insert(pw[i]);
			p2[L2++] = i;
		} else {
			p1[L1++] = i;
		}
	}
	sort(p1, p1+L1, cmp);
	sort(p2, p2+L2, cmp);
	S = INF;
	for (int i = 1; i <= n; i ++) {
		if (A[i].empty()) {
			puts("-1");
			exit(0);
		} else T += *A[i].begin();
	}
	for (int i = 0, j = 0; i < L1; i ++) {
		if (v[py[p1[i]]]) {
			T -= co[py[p1[i]]];
			co[py[p1[i]]] = min(co[py[p1[i]]], pw[p1[i]]);
			T += co[py[p1[i]]];
		} else {
			v[py[p1[i]]] = true;
			nw ++;
			co[py[p1[i]]] = pw[p1[i]];
			T += co[py[p1[i]]];
		}
		bool F = true;
		while (j < L2 && px[p2[j]] <= px[p1[i]]+k) {
			T -= *A[pz[p2[j]]].begin();
			A[pz[p2[j]]].erase(A[pz[p2[j]]].find(pw[p2[j]]));
			if (A[pz[p2[j]]].empty()) {
				F = false;
				break;
			}
			T += *A[pz[p2[j]]].begin();
			j++;
		}
		if (!F) break;
		if (nw == n) S = min(S, T);
	}
	if (S == INF) S = -1;
	cout << S << endl;
	return 0;
}