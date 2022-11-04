#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int t, l, r, F[32], G[32];

void f(int x){
	if(!x) return;
	int i;
	for(i = 1; (1 << i) <= x; i++);
	for(int j = 1; j < i; j++)
		F[j] += (1 << (i - 2));
	x -= (1 << (i - 1));
	F[i] += x + 1;
	f(x);
}

void g(int x){
	if(!x) return;
	int i;
	for(i = 1; (1 << i) <= x; i++);
	for(int j = 1; j < i; j++)
		G[j] += (1 << (i - 2));
	x -= (1 << (i - 1));
	G[i] += x + 1;
	g(x);
}

int main(){
	scanf("%d", &t);
	while(t--){
		memset(F, 0, sizeof(F));
		memset(G, 0, sizeof(G));
		scanf("%d%d", &l, &r);
		f(r), g(l - 1);
		int ans = 0;
		for(int i = 1; i < 32; i++)
			ans = max(ans, F[i] - G[i]);
		printf("%d\n", r - l + 1 - ans);
	}
	return 0;
}