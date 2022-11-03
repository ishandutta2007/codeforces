#include <cstdio>

const int MAXN = 1E5 + 10, MAXL = 50;
const int LIMIT = 2E4;

char buf[MAXL];
int a[MAXN], b[MAXN];

int main(){
	int n, K, cnt = 0;
	scanf("%d%d", &n, &K);
	for (int i = 0; i <= n; ++i){
		scanf("%s", buf);
		cnt += b[i] = buf[0] == '?';
		if (!b[i])
			sscanf(buf, "%d", &a[i]);
	}
	if (K == 0)
		puts(b[0] && n + 1 - cnt & 1 || !b[0] && a[0] == 0 ? "Yes" : "No");
	else if (cnt)
		puts(n & 1 ? "Yes" : "No");
	else{
		int c = 0;
		for (int i = n; i >= 0; --i){
			a[i] += c;
			c = a[i] * K;
			if (c > LIMIT || c < -LIMIT)
				break;
		}
		puts(c ? "No" : "Yes");
	}
	return 0;
}