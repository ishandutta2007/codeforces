#include <bits/stdc++.h>
using namespace std;
#define N 100005

int n, a[N], b[N], id[N];

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	scanf("%d", &n);
	int i, j;
	for(i = 0; i < n; i++){
		scanf("%d %d", a + i, b + i);
		id[i] = i;
	}
	sort(id, id + n, cmp);
	for(i = 0; i < n - 1; i++) if(b[id[i]] > b[id[i + 1]]) break;
	if(i < n - 1) puts("Happy Alex");
	else puts("Poor Alex");
}