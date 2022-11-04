#include <bits/stdc++.h>

using namespace std;

#define NN 101000

vector<int> L, R;
int N;
int ans, T;
int lt[NN], rt[NN];

int calc(int u) {
	int s = lower_bound(L.begin(), L.end(), u+1) - L.begin();
	s -= lower_bound(R.begin(), R.end(), u) - R.begin();
	return s;
}

int solve(int p) {
	p %= N;
	int s = calc(p) + calc(p+N);
	if(ans < s) ans = s, T = p;
}

int ok(int L, int R, int p) {
	if(p >= L and R >= p) return 1;
	p += N;
	if(p >= L and R >= p) return 1;
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("D.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, H, M, k;
	cin >> n >> H >> M >> k;
	M /= 2;
	for(int i=1; i<=n; i++) {
		int h, m;
		scanf("%d %d", &h, &m); m %= M;
		int l = (m + k) % M, r = m % M;
		if(l > r) r += M;
		lt[i] = l; rt[i] = r;
		L.push_back(l), R.push_back(r);
	}
	
	sort(L.begin(), L.end()); sort(R.begin(), R.end());
	N = M; ans = 0;
	for(auto u : L) solve(u);
	for(auto u : R) solve(u);
	
	vector<int> buf;
	for(int i=1; i<=n; i++) {
		if(!ok(lt[i], rt[i], T)) buf.push_back(i);
	}
	
	cout << n - ans << ' ' << T << endl;
	for(auto u : buf) printf("%d ", u); puts("");
	return 0;
}