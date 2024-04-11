#include <bits/stdc++.h>
using namespace std;
#define N 105

int a[N], b, c;

int main(){
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	c = n + 1;
	for(i = 0; i < m; i++){
		scanf("%d", &b);
		if(b < c){
			for(j = b; j < c; j++) a[j] = b;
			c = b;
		}
	}
	for(i = 1; i <= n; i++) printf("%d ", a[i]);
}