#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
char s[N], opt[10], ans[N];
int cnt[6], m, sum[1 << 6], der[1 << 6], n;
int lim[N];

int chk(int c) {
	int flag = 1;
	for(int i = 0; i < 1 << 6; i++) if(i >> c & 1) der[i]--;
	for(int i = 0; i < 1 << 6; i++) flag &= der[i] >= sum[i];
	for(int i = 0; i < 1 << 6; i++) if(i >> c & 1) der[i]++;
	return flag;
}

int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int i = 1; i <= n; i++) ++cnt[s[i] - 'a'], lim[i] = (1 << 6) - 1;
	m = get();
	for(int i = 1, len, nw, pos; i <= m; i++) {
		pos = get(), scanf("%s", opt + 1), len = strlen(opt + 1), nw = 0;
		for(int j = 1; j <= len; j++) nw |= 1 << (opt[j] - 'a');
		lim[pos] = nw;
	}
	for(int i = 1; i <= n; i++) ++sum[lim[i]];
	for(int i = 1; i <= 6; i++)
		for(int j = 0; j < 1 << 6; j++)
			if(j >> (i - 1) & 1) sum[j] += sum[j ^ (1 << (i - 1))], der[j] = der[j] + cnt[i - 1]; 
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 1 << 6; j++) if((j & lim[i]) == lim[i]) --sum[j];
		int flag = 0;
		for(int j = 0; j < 6; j++) if(lim[i] >> j & 1)
			if(chk(j)) { 
				ans[i] = 'a' + j, flag = 1; 
				for(int k = 0; k < 1 << 6; k++) if(k >> j & 1) der[k]--;
				break; 
			}
		if(!flag) return printf("Impossible\n"), 0;
	}
	printf("%s", ans + 1);
	return 0;
}