#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int n;
char s[MAXN];
int a[MAXN], t[MAXN];

bool check(int n){
	for (int i = 0; i <= n; ++i)
		t[i] = s[i];
	int n0 = n - 1 >> 1;
	for (int i = 0; i <= n0; ++i){
		if (t[i] < 0)
			t[i] += 10, --t[i + 1];
		int sum;
//		printf("%d %d %d %d\n", n, t[i], t[n - i - 1], t[n - i]);
		if (t[n - i] == 0 || t[i] == 9){
			if (t[i] == 9 && t[n - i])
				--t[n - i], t[n - i - 1] += 10;
			a[i] = t[i] >> 1, a[n - i - 1] = t[i] + 1 >> 1;
			if ((t[n - i - 1] -= t[i]) < 0)
				return false;
			t[i] = 0;
		}
		else if (t[n - i] == 1){
			a[i] = t[i] + 10 >> 1, a[n - i - 1] = t[i] + 11 >> 1;
			t[n - i] = 0;
			if ((t[n - i - 1] -= t[i]) < 0)
				return false;
			--t[i + 1];
			t[i] = 0;
		}
		else
			return false;
//		printf("-- %d %d\n", a[i], a[n - i - 1]);
/*		for (int i = n; i >= 0; --i)
			printf("%d ", t[i]);
		puts("");*/
	}
	if (a[n - 1] == 0)
		return false;
	for (int i = 0; i < n; ++i)
		t[i] = a[i] + a[n - i - 1];
	t[n] = 0;
	for (int i = 0; i < n; ++i)
		if (t[i] > 9)
			t[i] -= 10, ++t[i + 1];
	for (int i = 0; i <= n; ++i)
		if (t[i] != s[i] || a[i] < 0 || a[i] > 9)
			return false;
	for (int i = n - 1; i >= 0; --i)
		putchar(a[i] + '0');
	return true;
}

int main(){
	scanf("%s", s);
	int n = strlen(s);
	reverse(s, s + n);
	for (int i = 0; i < n; ++i)
		s[i] -= '0';
	if (!check(n) && !check(n - 1))
		puts("0");
	return 0;
}