#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> b(2 * n, 0);
    int mn = 0;
    forn (i, n) {
    	if (s[i] == '(') {
    		b[i + 1] = b[i] + 1;
		} else {
    		b[i + 1] = b[i] - 1;
		}
		mn = min(mn, b[i + 1]);
    }
    if (b[n] != 0) {
    	cout << 0 << endl << "1 1" << endl;
    	return 0;
    }
    int ans = 0;
    int l = 0, r = 0;
    forn (i, n) {
    	b[i] -= mn;
    	ans += b[i] == 0;
    }
    int cnt_0 = ans;
    forn (i, n) {
    	b[i + n] = b[i];
    }
    for (int i = 0; i < n; ++i) {
   		if (s[i] != '(' || b[i] != 0) {
   			continue;
   		}
   		int cnt_1 = 0;
   		for (int j = i + 1; j < 2 * n; ++j) {
   			cnt_1 += b[j] == 1;
   			if (s[j % n] != ')' || b[j] != 1) {
   				continue;
   			}
   			if (cnt_1 > ans) {
   				ans = cnt_1;
   				l = i;
   				r = j % n;
   			}
   			i = j;
   			break;
   		}
    }
    for (int i = 0; i < n; ++i) {
   		if (s[i] != '(' || b[i] != 1) {
   			continue;
   		}
   		int cnt_2 = 0;
   		for (int j = i + 1; j < 2 * n; ++j) {
   			cnt_2 += b[j] == 2;
   			if (s[j % n] != ')' || b[j] != 2) {
   				continue;
   			}
   			if (cnt_2 + cnt_0 > ans) {
   				ans = cnt_2 + cnt_0;
   				l = i;
   				r = j % n;
   			}
   			i = j;
   			break;
   		}
    }
    cout << ans << endl;
    cout << l + 1 << " " << r + 1 << endl;
}