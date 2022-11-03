#include <cstdio>

const int MAXN = 3E5 + 10;

char s[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	s[0] = 'a';
	scanf("%s", s + 1);
	int cnt = 0, seg = 0;
	for (int i = 1; i <= n; ++i){
		cnt += s[i] == '.';
		seg += s[i] == '.' && s[i - 1] != '.';
	}
	char com[10];
	for (int i = 0; i < m; ++i){
		int t;
		scanf("%d%s", &t, com);
		int x = s[t] == '.' ^ com[0] != '.' ? 0 : s[t] == '.' ? 1 : -1;
		s[t] = com[0];
		cnt -= x;
		seg += x * ((s[t - 1] == '.') + (s[t + 1] == '.') - 1);
		printf("%d\n", cnt - seg);
	}
	return 0;
}