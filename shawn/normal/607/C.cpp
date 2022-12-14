#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 10;
int n, p[N];
char a[N], b[N];

void kmp() {
	p[1] = 0;
	for (int j = 0, i = 2; i <= n + n; i ++){
		for (; j && a[j + 1] != a[i]; j = p[j]);
		if (a[j + 1] == a[i]) j ++;
		p[i] = j;
	}
}

int main() {
	scanf("%d", &n); n--;
	scanf("%s%s", a + 1, b + 1);
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 'N') a[i] = 'S';
		else if (a[i] == 'S') a[i] = 'N';
		else if (a[i] == 'W') a[i] = 'E';
		else if (a[i] == 'E') a[i] = 'W';
	}
	for (int i = 1; i <= n / 2; i ++) swap(a[i], a[n - i + 1]);
	for (int i = 1; i <= n; i ++) a[i + n] = b[i];
	kmp();
	puts(!p[n + n] ? "YES" : "NO");
	return 0;
}