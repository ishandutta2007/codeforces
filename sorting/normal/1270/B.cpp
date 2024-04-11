#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int a[MAXN];

void solve(){
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n - 1; ++i){
		if(max(a[i], a[i + 1]) - min(a[i], a[i + 1]) >= 2){
			cout << "YES\n";
			cout << i + 1 << " " << i + 2 << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}