#include <bits/stdc++.h>
using namespace std;

int vis[1000011];

int main(){
	int n;
	scanf("%d", &n);
	int x;
	for(int i = 1; i < n; i ++) scanf("%d", &x), vis[x] = 1;
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		printf("%d\n", i);
		return 0;
	}
}