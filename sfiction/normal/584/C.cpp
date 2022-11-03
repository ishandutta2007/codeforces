#include <cstdio>

const int MAXN = 1E5 + 10;

int n, m;
char a[MAXN], b[MAXN];

char diff(char a, char b){
	if (a != 'a' && b != 'a')
		return 'a';
	else if (a != 'b' && b != 'b')
		return 'b';
	else
		return 'c';
}

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s%s", a, b);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += a[i] != b[i];
	if (m >= cnt){
		int t = m - cnt;
		for (int i = 0; i < n; ++i){
			if (a[i] != b[i])
				putchar(diff(a[i], b[i]));
			else if (t){
				--t;
				putchar(diff(a[i], b[i]));
			}
			else
				putchar(a[i]);
		}
		puts("");
	}
	else if (m * 2 >= cnt){
		int t = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] != b[i]){
				++t;
				if (t <= m * 2 - cnt)
					putchar(diff(a[i], b[i]));
				else if (t <= m)
					putchar(b[i]);
				else
					putchar(a[i]);
			}
			else
				putchar(a[i]);
		puts("");
	}
	else
		puts("-1");
	return 0;
}