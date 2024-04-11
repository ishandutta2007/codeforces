#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int a[MAXN];

void solve(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}

	int j = 1;
	for(int i = 1; i <= n; ++i){
		int k;
		for(k = 1; k <= n; ++k){
			if(a[k] == i){
				break;
			}
		}

		int pr = k;
		for(; k > j; --k){
			swap(a[k - 1], a[k]);
		}
		if(pr == j){
			++j;
		}
		else{
			j = max(j, pr);
		}
	}

	for(int i = 1; i <= n; ++i){
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while(q--){
		solve();
	}
}