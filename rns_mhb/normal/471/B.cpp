#include <bits/stdc++.h>
using namespace std;

int n, a[2005], id[2005], sum;
bool x, y;

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", a + i);
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	for(i = 0; i < n; i++) if(a[id[i]] == a[id[i + 1]]) sum++;
	if(sum < 2) puts("NO");
	else{
		puts("YES");
		for(i = 1; i <= n; i++) printf("%d ", id[i]);
		for(i = 1, puts(""); i <= n; i++){
			if(a[id[i]] == a[id[i + 1]] && !y){
				swap(id[i], id[i + 1]);
				y = 1;
			}
			printf("%d ", id[i]);
		}
		for(i = 1, puts(""); i <= n; i++){
			if(a[id[i]] == a[id[i + 1]]){
				if(!x) x = 1;
				else swap(id[i], id[i + 1]);
			}
			printf("%d ", id[i]);
		}
	}
}