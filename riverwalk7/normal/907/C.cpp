#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <set>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

bool f[30], temp[30];
int cnt = 26, ans = 0;

int main()
{
//	freopen("c.in", "r", stdin);
//	freopen("c.out", "w", stdout);
 	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < 26; i ++)
		f[i] = 1;
	string s;
	char tp;
	for (int i = 1; i <= n; i ++) {
		cin >> tp >> s;
		if (tp == '.') {
			for (int i = 0; i < s.size(); i ++) {
				if (f[s[i] - 'a'] == 1)
					cnt --;
				f[s[i] - 'a'] = 0;
			}
		}
		if (tp == '!') {
			if (cnt == 1)
				ans ++;
			memset(temp, 0, sizeof temp);
			for (int i = 0; i < s.size(); i ++)
				temp[s[i] - 'a'] = 1;
			for (int i = 0; i < 26; i ++) {
				if (f[i] == 1 && temp[i] == 0)
					cnt --;
				f[i] = (f[i] & temp[i]);
			}
		}
		if (tp == '?') {
			if (i != n && cnt == 1) {
				ans ++;
				continue;
			}
			if (f[s[0] - 'a'] == 1)
				cnt --;
			f[s[0] - 'a'] = 0;
		}
//		cout << cnt << endl;
	}
	cout << ans << endl;
	return 0;
}