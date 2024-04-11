#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

const int mod = 1000000007;

string s[110];

char get_char(int i) {
	if (i < 26) {
		return 'a' + i;
	} else if (i < 52) {
		return 'A' + i - 26;
	} else {
		return '0' + i - 52;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin >> t;
    forn (q, t) {
    	int n, m, k;
		cin >> n >> m >> k;
		int cnt_all = 0;
		forn (i, n) {
			cin >> s[i];
			forn (j, m) {
				cnt_all += s[i][j] == 'R';
			}
		}
		vector<string> ans(n);
		forn (i, n) {
			forn (j, m) {
				ans[i] += 'a';
			}
		}
		int cur = 0;
		int cnt = 0;
		forn (i, n) {
			if (i % 2) {
				forn (j, m) {
					ans[i][j] = get_char(min(cur, k - 1));
					cnt += s[i][j] == 'R';
					if (cnt * k >= cnt_all * (cur + 1)) {
						++cur;
					}
				}
			} else {
				for (int j = m - 1; j >= 0; --j) {
					ans[i][j] = get_char(min(cur, k - 1));
					cnt += s[i][j] == 'R';
					if (cnt * k >= cnt_all * (cur + 1)) {
						++cur;
					}
				}
			}
		}
		forn (i, n) {
			cout << ans[i] << endl;
		}
    }
}