#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int MX = 500005;

int Tc, N;
string s;
int cnt[5];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		memset(cnt, 0, sizeof cnt);
		cin >> s;
		for(int i = 0 ; i < s.size() ; i ++) {
			cnt[s[i] - 'A'] ++;	
		}
		if(cnt[1] == cnt[0] + cnt[2]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;

}