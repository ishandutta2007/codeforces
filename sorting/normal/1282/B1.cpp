#include <bits/stdc++.h>

using namespace std;

bool check(const int &mid, const vector<int> &a, int p, int k){
	int i = mid;
	while(true){
		p -= a[i];
		i -= k;
		if(i < 0){
			i += k;
			for(int j = 0; j < i; ++j)
				p -= a[j];
			break;
		}
	}

	return (p >= 0);
}

void solve(){
	int n, p, k;
	cin >> n >> p >> k;

	vector<int> a;
	for(int i = 0; i < n; ++i){
		a.push_back(0);
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int mx = -1, p2 = p;
	for(int i = k - 1; i < n; i += k){
		if(p2 >= a[i]){
			p2 -= a[i];
			mx = i;
		}
	}

	int l = mx, r = min(mx + k - 1, n - 1);
	while(l != r){
		int mid = (l + r + 1) >> 1;
		if(check(mid, a, p, k))
			l = mid;
		else
			r = mid - 1;
	}

	cout << l + 1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}