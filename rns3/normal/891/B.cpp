#include <bits/stdc++.h>

using namespace std;



#define N 33



int a[N], b[N], id[N];



bool cmp(int i, int j) {

	return a[i] < a[j];

}



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), id[i] = i;

	sort(id + 1, id + n + 1, cmp);

	for (int i = 1; i < n; i ++) b[id[i]] = a[id[i+1]];

	b[id[n]] = a[id[1]];

	for (int i = 1; i <= n; i ++) printf("%d%c", b[i], (i == n) ? '\n' : ' ');



	return 0;

}