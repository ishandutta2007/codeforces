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

#define INF 1000000007
#define N 1000100
int n;
int a[N];
int w[N];
int st[N];
int L[N];
ll S[N];
int m;
int f[N*4];

int*b;
void blt(int p, int l, int r) {
	if (l == r-1) {
		f[p] = b[l];
		return;
	}
	int mid = (l+r)/2;
	blt(p*2+1, l, mid);
	blt(p*2+2, mid, r);
	f[p] = max(f[p*2+1], f[p*2+2]);
}

int ask(int p, int l, int r, int L, int R) {
	if (L <= l && r <= R) return f[p];
	int S = -INF;
	int mid = (l+r)/2;
	if (L < mid) S = max(S, ask(p*2+1, l, mid, L, R));
	if (mid < R) S = max(S, ask(p*2+2, mid, r, L, R));
	return S;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	ll T = 0;
	for (int i = 0; i < n; i ++) {
		cin >> L[i];
		st[i+1] = st[i] + L[i];
		w[i] = 0;
		for (int j = 0; j < L[i]; j ++) {
			cin >> a[st[i] + j];
			w[i] = max(w[i], a[st[i]+j]);
		}
		T += w[i];
	}
	for (int i = 0; i < m; i ++) S[i] = T;
	for (int i = 0; i < n; i ++) {
		if (L[i]*2 > m) {
			b = a+st[i];
			blt(0, 0, L[i]);
			for (int j = 0; j < m; j ++) {
				int l = max(0, L[i]-1-(m-1-j));
				int r = min(j, L[i]-1);
				int u = ask(0, 0, L[i], l, r+1);
				if (m-1-j >= L[i] || j >= L[i]) u = max(u, 0);
				S[j] += u-w[i];
			}
		} else {
			int u = 0;
			for (int j = 0; j < L[i]; j ++) {
				u = max(u, a[st[i]+j]);
				S[j] += u-w[i];
			}
			u = 0;
			for (int j = 0; j < L[i]; j ++) {
				u = max(u, a[st[i]+L[i]-j-1]);
				S[m-j-1] += u-w[i];
			}
		}
	}
	for (int i = 0; i < m; i ++) {
		cout << S[i];
		if (i == m-1) cout << endl;
		else cout << " ";
	}
	return 0;
}