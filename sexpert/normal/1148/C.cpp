#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 5;
int posit[MAXN], perm[MAXN];
vector<ii> ans;

void do_swap(int i, int j) {
	ans.push_back({i, j});
	int a = perm[i], b = perm[j];
	swap(perm[i], perm[j]);
	posit[a] = j;
	posit[b] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	m = n/2;
	for(int i = 1; i <= n; i++) {
		cin >> perm[i];
		posit[perm[i]] = i;
	}
	for(int k = 1; k <= m; k++) {
		if(posit[m + k] <= m)
			do_swap(posit[m + k], n);
		do_swap(posit[m + k], k);
		do_swap(posit[m + k], m + k);
		if(posit[k] <= m)
			do_swap(posit[k], n);
		do_swap(posit[k], k);
	}
	cout << ans.size() << '\n';
	for(auto x : ans) 
		cout << x.first << " " << x.second << '\n';
}