#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, d;
	cin >> n >> d;

	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 1; i < n; ++i){
		int k = d / i;
		if(k >= a[i]){
			d -= i * a[i];
			a[0] += a[i];
		}
		else{
			d = d % i;
			a[0] += k;
		}
	}

	cout << a[0] << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}