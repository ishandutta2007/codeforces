#include <bits/stdc++.h>

using namespace std;

const int MAXN = 37;

string s[MAXN], t[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int i = 0; i < m; ++i)
		cin >> t[i];

	int q;
	cin >> q;

	while(q--){
		int x;
		cin >> x;

		cout << s[(x - 1) % n] << t[(x - 1) % m] << "\n";
	}

	return 0;
}