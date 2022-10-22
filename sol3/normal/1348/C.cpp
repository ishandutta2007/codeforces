#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

int t, n, K, cnt[26];
char s[100005];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> K;
		for (register int i = 1;i <= n;i++) cin >> s[i];
		sort(s + 1, s + n + 1);
		memset(cnt, 0, sizeof(cnt));
		for (register int i = 1;i <= n;i++) cnt[s[i] - 'a']++;
		
		register int type = 0;
		for (register int i = 0;i < 26;i++) type += Min(cnt[i], 1);
		if (type == 1) {
			for (register int i = 1;i <= (n + K - 1) / K;i++) putchar(s[i]);
			putchar('\n');
		} else if (type == 2) {
			if (cnt[s[1] - 'a'] < K) {
				putchar(s[n]);
			} else if (cnt[s[1] - 'a'] == K) {
				putchar(s[1]);
				for (register int i = 1;i <= (cnt[s[n] - 'a'] + K - 1) / K;i++) putchar(s[n]);
			} else {
				for (register int i = K;i <= n;i++) putchar(s[i]);
			}
			putchar('\n');
		} else {
			if (cnt[s[1] - 'a'] >= K) {
				for (register int i = K;i <= n;i++) putchar(s[i]);
				putchar('\n');
			} else {
				putchar(s[K]);
				putchar('\n');
			}
		}
		/*
		register int j = 0;
		for (register int i = 0;i < 26;i++) {
			for (register int k = 0;k < cnt[i];k++, j++) ans[j % K + 1] += i + 'a';
			if (cnt[i] % K || (cnt[i] && type >= 3)) {
				for (i++;i < 26;i++) {
					for (;cnt[i] && j < K;cnt[i]--, j++) ans[j % K + 1] += i + 'a';
					if (j >= K) break;
				}
				for (;i < 26;i++) {
					for (register int j = 0;j < cnt[i];j++) ans[1] += i + 'a';
					//cout << ans[1] << endl;
				}
			}
		}
		sort(ans + 1, ans + K + 1);
		cout << ans[K] << endl;
		*/
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}