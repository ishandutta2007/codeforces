#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

void solve(){
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int mn = inf, mx = -2;
	for(int i = 0; i < n; ++i){
		if(a[i] == -1){
			if(i != 0 && a[i - 1] != -1){
				mn = min(mn, a[i - 1]);
				mx = max(mx, a[i - 1]);
			}
			if(i != n - 1 && a[i + 1] != -1){
				mn = min(mn, a[i + 1]);
				mx = max(mx, a[i + 1]);
			}
		}
	}

	if(mx == -2){
		cout << "0 1\n";
		return;
	}

	int k = (mx - mn) / 2 + mn;
	for(int i = 0; i < n; ++i){
		if(a[i] == -1)
			a[i] = k;
	}

	int m = 0;
	for(int i = 0; i < n - 1; ++i)
		m = max(m, abs(a[i + 1] - a[i]));

	cout << m << " " << k << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}