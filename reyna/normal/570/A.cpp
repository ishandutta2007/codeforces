//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N];
int b[N];
int in[N][N];
int index[N];
int cnt[N];
int main() {
	int n,m; cin >> n >> m;;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	for(int i = 0; i < m; ++i) {
		int mx = 0;
		for(int j = 0; j < n; ++j) mx = max(mx,a[i][j]);
		int id = -1;
		for(int j = 0; j < n; ++j) if(a[i][j] == mx) {
			id = j;
			break;
		}
		cnt[id]++;
	}
	int mx = 0;
	for(int i = 0; i < n; ++i) mx = max(mx,cnt[i]);
	for(int i = 0; i < n; ++i) if(cnt[i] == mx) {
		cout << i + 1 << endl;
		return 0;
	}
}