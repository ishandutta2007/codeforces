#include <bits/stdc++.h>

using namespace std;

const int MX = 500005;

int Tc, N, k;
int vis[MX], ans[MX];
char s[10];

int main() {
#ifndef ONLINE_JUDGE
//	freopen("I", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for(int i = 0; i < MX; i+=3) vis[i] = 1;
	for(int i = 1; i < MX; i++){
		if(i % 10 == 3) continue;
		if(vis[i]) continue;
		ans[k ++] = i;
	}
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		cout << ans[N - 1] << endl;
	}

	return 0;

}