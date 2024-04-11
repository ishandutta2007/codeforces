#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
int f[maxn];
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int t; scanf("%d", &t);
		f[t] = true;
	}
	if(f[1])
		printf("1\n");
	else{
		int pos = 1;
		for(int i = 0; i < k; i++){
			int u, v; scanf("%d%d", &u, &v);
			if(u == pos) pos = v;
			else if(v == pos) pos = u;
			if(f[pos]) break;
		}
		printf("%d\n", pos);
	}
	return 0;
}