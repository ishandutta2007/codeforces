#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN], b[MAXN], c[MAXN], a2[MAXN], b2[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}

	for(int i = 0; i < n; ++i){
		a2[a[i] - 1] = i + 1;
		b2[b[i] - 1] = i + 1;
	}

	for(int i = 0; i < n; ++i){
		c[a2[i] - 1] = b2[i];
	}

	int ans = 0, mx = c[0];
	for(int i = 1; i < n; ++i){
		if(mx > c[i]){
			++ans;
		}
		else{
			mx = c[i];
		}
	}

	cout << ans << "\n";

	return 0;
}