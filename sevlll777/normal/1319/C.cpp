
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	string now = s;
	for (char y = 'z'; y >= 'a'; y--) {
	    for (int uu = 0; uu < 120; uu++) {
	        string now2 = "";
    		for (int i = 0; i < now.size(); i++) {
    			if ((now[i] == y) && ((i != 0 && now[i - 1] == y - 1) || (i != (int) now.size() - 1 && now[i + 1] == y - 1))) {
    				continue;
    			} else {
    				now2 += now[i];
    			}
    		}
    		now = now2;
	    }
	}
	cout << (int) s.size() - (int) now.size();
}