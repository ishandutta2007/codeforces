#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, x;
	cin >> n >> x;

	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int ans = (x / a[0]) + (bool)(x % a[0]);
	if(ans == 1){
		for(int i = 0; i < n; ++i){
			if(a[i] == x){
				cout << "1\n";
				return;
			}
		}
		ans = 2;
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