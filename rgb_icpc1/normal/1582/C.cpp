#include <bits/stdc++.h>

using namespace std;

const int MX = 100005;

int Tc, N;
string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		cin >> s;
		int ans = N + 1;
		for(int c = 0 ; c < 26 ; c ++) {
			int cnt = 0;
			i = 0, j = N - 1;
			while(i <= j) {
				if(s[i] == s[j]) i ++, j --;
				else if(s[i] == 'a' + c) cnt ++, i ++;
				else if(s[j] == 'a' + c) cnt ++, j --;
				else {
					cnt = N + 1;
					break;
				}
			}
			if(cnt < ans) ans = cnt;
		}
		if(ans == N + 1) cout << "-1" << endl;
		else cout << ans << endl;
	}

	return 0;

}