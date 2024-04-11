#include <bits/stdc++.h>
using namespace std;
#define M 200010
char s[M];
int cnt[30], n, b[30], I, len;
int main() {
//	freopen("C.in", "r", stdin);
	scanf("%s", s);
	for (int i = 0; s[i]; i++) cnt[s[i]-'a']++;
	int bf = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] & 1) b[n++] = i;
	}
	for (int i = 0; i < n / 2; i++) {
		cnt[b[i]]++; cnt[b[n-1-i]]--;
	}
	if (n & 1) I = b[n/2];
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < cnt[i] / 2; j++) s[len++] =i + 'a';
	}
	s[len] = 0;
	printf("%s", s); if (n & 1) printf("%c", I + 'a');
	if (len) reverse(s, s + len); printf("%s", s);
}