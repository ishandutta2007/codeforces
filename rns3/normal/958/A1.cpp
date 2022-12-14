#include <bits/stdc++.h>

using namespace std;



#define N 12



char s[N][N], t[N][N];



int n;



bool func_1() {

	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (s[i][j] != t[i][j]) return 0;

	return 1;

}



bool func_2() {

	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (s[i][j] != t[n-1-j][i]) return 0;

	return 1;

}



bool func_3() {

	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (s[i][j] != t[n-1-i][n-1-j]) return 0;

	return 1;

}



bool func_4() {

	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (s[i][j] != t[j][n-1-i]) return 0;

	return 1;

}



int main() {

	scanf("%d\n", &n);

	for (int i = 0; i < n; i ++) gets(s[i]);

	for (int i = 0; i < n; i ++) gets(t[i]);



	bool ok = 0;



	if (func_1()) ok = 1;

	else if (func_2()) ok = 1;

	else if (func_3()) ok = 1;

	else if (func_4()) ok = 1;



	for (int i = 0; i < n; i ++) for (int j = 0, k = n - 1; j < k; j ++, k --) swap(t[i][j], t[i][k]);



	if (func_1()) ok = 1;

	else if (func_2()) ok = 1;

	else if (func_3()) ok = 1;

	else if (func_4()) ok = 1;



	puts(ok ? "Yes" : "No");



	return 0;

}