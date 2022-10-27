#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> a(n+1);
	vector<int> pos(52, 0);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (pos[a[i]] == 0) pos[a[i]] = i;
	}
	
	while (q --) {
		int x;
		cin >> x;
		cout << pos[x] << " ";
		for (int i = 1; i <= 50; i ++) if (pos[i] && pos[i] < pos[x]) pos[i] ++;
		pos[x] = 1;
	} 
}