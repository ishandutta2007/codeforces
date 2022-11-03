#include <bits/stdc++.h>

const int MAXN = 1E4 + 10;

char s[MAXN], ss[MAXN];

int main(){
	int n;
	scanf("%s", s + 1);
	scanf("%d", &n);
	while (n--){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		k %= r - l + 1;
		for (int i = 0; i < k; ++i)
			ss[l + i] = s[r - k + 1 + i];
		for (int i = l + k; i <= r; ++i)
			ss[i] = s[i - k];
		strncpy(s + l, ss + l, r - l + 1);
	}
	puts(s + 1);
	return 0;
}