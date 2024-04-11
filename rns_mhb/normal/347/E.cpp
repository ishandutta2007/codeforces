#include <bits/stdc++.h>
using namespace std;
#define N 100005

int x[N], y[10 * N], n;
int a, b;

int main(){
	int i, j, len, ans = 0, pos = 0, posds = -1;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", x + i);
	scanf("%d %d", &a, &b);
	for(i = 0; i < a - b; i++) y[i] = i + 1;
	sort(x, x + n);
	len = unique(x, x + n) - x;
	for(i = 0; i < len; i++){
		for(j = (b - 1) / x[i] + 1; j * x[i] < a; j++) y[j * x[i] - b] = j * x[i] - b + x[i] - 1;
	}
	while(pos < a - b){
		j = pos;
		for(i = posds; i <= pos; i++) j = max(j, y[i]);
		posds = pos + 1;
		pos = j;
		ans++;
	}
	printf("%d", ans);
}