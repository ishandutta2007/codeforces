#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;

int s[maxn];

bool check(int n, int m, int a, int b){
	if (m > b-a-1)
		return false;
	int T = b-2;
	for (int i = m-1; i >= 0; i--){
		if (T < s[i])
			return false;
		T --;
	}
	return true;
}

void solve(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; i++)
		cin >> s[i];
	if (a > b)
		a = n-a+1, b = n-b+1;
	sort(s,s+m);
	int lo = 0, hi = m+1;
	while (hi - lo > 1){
		int mid = (lo+hi) >> 1;
		if (check(n, mid, a, b))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}