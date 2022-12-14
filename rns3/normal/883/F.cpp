#include <bits/stdc++.h>
using namespace std;

#define N 502

char t[N], tt[N];
string s;
int n;

map <string, bool> mp;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d\n", &n);
	int ans = 0;
	while (n --) {
		gets(t);
		int m = strlen(t);//puts(t);
		int k = 0;
		for (int i = 0; i < m; i ++) {
			if (t[i] == 'h') {
				while (k > 0 && tt[k-1] == 'k') k --;
			}
			tt[k++] = t[i];
		}
		s.clear();
		for (int i = 0; i < k; i ++) {
			if (tt[i] != 'u') s.push_back(tt[i]);
			else s.push_back('o'), s.push_back('o');
		}
		//for (int i = 0; i < s.size(); i ++) printf("%c", s[i]);puts("");
		if (!mp[s]) ans ++;
		mp[s] = 1;
	}
	printf("%d\n", ans);

	return 0;
}