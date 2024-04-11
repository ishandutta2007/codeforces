#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
string s[N], t[N]; int n;
bool check() {
	vector<bool> flip(n + 1, 0);
	for (int i = 1; i <= n; i ++) {
		if (s[1][i] != t[1][i]) flip[i] = 1;
	}
	for (int i = 2; i <= n; i ++) {
		bool f[2] = {0};
		for (int j = 1; j <= n; j ++) {
			f[flip[j] ^ (s[i][j] != t[i][j])] = 1;
		}
		if (f[0] && f[1]) return false;
	}
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);	
    int T; cin >> T;
    while (T --) {
    	cin >> n;
    	for (int i = 1; i <= n; i ++) {cin >> s[i];s[i]="0"+s[i];}
    	for (int i = 1; i <= n; i ++) {cin >> t[i];t[i]="1"+t[i];}
    	bool ans = check();
    	for (int i = 1; i <= n; i ++) {
    		s[1][i] = (char)((int)'1' + '0' - s[1][i]);
    	}
    	ans |= check();
    	cout << (ans?"YES":"NO") << endl;
    }	
}