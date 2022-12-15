#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 3507;

int a[kMaxN];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;

	//--m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	vector<int> v;
	for(int i = 1; i <= n; ++i){
		if(i + (n - m) <= n)
			v.push_back(max(a[i], a[i + (n - m)]));
	}

	int t = v.size();

	if(k >= t){
		int ans = 0;
		for(int x: v)
			ans = max(ans, x);
		cout << ans << "\n";
		return;
	}

	multiset<int> ms;
	int ans = 0;
	for(int i = 0; i <= k; ++i){
		if(i == 0){
			for(int j = 0; j < t - k; ++j)
				ms.insert(v[j]);
			ans = max(ans, *ms.begin());
			continue;
		}

		ms.erase(ms.find(v[i - 1]));
		ms.insert(v[i + (t - k) - 1]);
		ans = max(ans, *ms.begin());
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}