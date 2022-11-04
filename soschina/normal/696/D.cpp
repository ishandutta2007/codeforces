#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 201;

int n, a[MAXN], ch[MAXN][26], fail[MAXN], val[MAXN], idx = 1;
char s[MAXN];
int q[MAXN], l, r;

long long buf, trans[MAXN][MAXN], ans[MAXN][MAXN], tmp[MAXN][MAXN], ANS = 0x8000000000000000;

void opt_max(long long a[][MAXN], long long b[][MAXN]){
	memset(tmp, -1, sizeof(long long) * idx * MAXN);
	for(int i = 0; i < idx; i++)
		for(int j = 0; j < idx; j++)
			for(int k = 0; k < idx; k++)
				if(~a[i][k] && ~b[k][j]) tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
	memcpy(a, tmp, sizeof(long long) * idx * MAXN);
}

int main(){
	scanf("%d%I64d", &n, &buf);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		int p = 0;
		for(char *c = s; *c != '\0'; c++)
			p = ch[p][*c - 'a'] ? ch[p][*c - 'a'] : ch[p][*c - 'a'] = idx++;
		val[p] += a[i];
	}
	for(int i = 0; i < 26; i++)
		if(ch[0][i]) q[r++] = ch[0][i];
	while(l != r){
		int &p = q[l++];
		val[p] += val[fail[p]];
		for(int i = 0; i < 26; i++){
			if(ch[p][i]){
				fail[ch[p][i]] = ch[fail[p]][i];
				q[r++] = ch[p][i];
			}else ch[p][i] = ch[fail[p]][i];
		}
	}
	memset(trans, -1, sizeof(long long) * idx * MAXN);
	for(int i = 0; i < idx; i++)
		for(int j = 0; j < 26; j++)
			trans[i][ch[i][j]] = val[ch[i][j]];
	memcpy(ans, trans, sizeof(long long) * idx * MAXN);
	buf--;
	while(buf){
		if(buf & 1) opt_max(ans, trans);
		opt_max(trans, trans);
		buf >>= 1;
	}
	for(int i = 0; i < idx; i++)
		ANS = max(ANS, ans[0][i]);
	printf("%I64d", ANS);
	return 0;
}