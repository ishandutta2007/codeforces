#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int l[MAXN], r[MAXN], s[MAXN], w[MAXN], v[MAXN];
int dp[2*MAXN][MAXN];
vector<int> wr[2*MAXN];

int calc(int str, int i) {
	if(dp[str][i] != -1)
		return dp[str][i];
	int L = l[i], R = r[i];
	vector<int> prf(2*MAXN);
	prf[L] = 0;
	for(int x = L + 1; x <= R; x++) {
		prf[x] = prf[x - 1];
		for(auto j : wr[x]) {
			if(l[j] == L && r[j] == R)
				continue;
			if(l[j] < L || w[j] > str)
				continue;
			prf[x] = max(prf[x], calc(min(str - w[j], s[j]), j) + prf[l[j]]);
		}
	}
	return dp[str][i] = v[i] + prf[R];
}

int main() {
	int n, S;
	cin >> n >> S;
	l[0] = 0;
	r[0] = 2*n;
	s[0] = S;
	w[0] = 0;
	v[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i] >> w[i] >> s[i] >> v[i];
		wr[r[i]].push_back(i);
	}
	for(int i = 0; i < 2*MAXN; i++)
		for(int j = 0; j < MAXN; j++)
			dp[i][j] = -1;
	cout << calc(S, 0) << endl;
	/*for(int str = 0; str <= S; str++) {
		cout << "strength = " << str << '\n';
		for(int i = 0; i <= n; i++)
			cout << calc(str, i) << '\n';
	}*/
}