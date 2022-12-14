#include <bits/stdc++.h>

using namespace std;



#define N 2020



int n;



char s[N], t[N];

char w[N];



int cnt[N];



char tmp[N];



int find_(int st, char c) {

	for (int i = st; i < n; i ++) if (tmp[i] == c) return i;

	assert(0);

}



int e;

int x[N<<2];



char now[N];



void oper(int y) {

	x[++e] = y;

	for (int i = n - y, j = y - 1; i < n; i ++, j --) now[j] = tmp[i];

	for (int i = 0, j = y; i < n - y; i ++, j ++) now[j] = tmp[i];

	for (int i = 0; i < n; i ++) tmp[i] = now[i];

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d\n", &n);

	gets(s), gets(t);

	for (int i = 0; i < n; i ++) cnt[s[i]] ++, cnt[t[i]] --;

	for (char c = 'a'; c <= 'z'; c ++) if (cnt[c]) {

		puts("-1");

		return 0;

	}

	for (int i = 0; i < n; i += 2) w[i] = t[(i/2)+(n/2)];

	for (int i = 1; i < n; i += 2) w[i] = t[(n/2)-((i+1)/2)];

	for (int i = 0; i < n; i ++) tmp[i] = s[i];

	for (int i = 0; i < n; i ++) {

		int j = find_(i, w[i]);

		int a = i, c = n - j - 1, b = n - a - c - 1;

		oper(c + 1);

		oper(b);

		oper(a + 1);

	}

	if (n % 2 == 0) oper(n);

	printf("%d\n", e);

	for (int i = 1; i <= e; i ++) printf("%d ", x[i]);

	puts("");



	return 0;

}