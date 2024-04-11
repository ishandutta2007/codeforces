#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 1;

int n, a[MAXN], b[2][MAXN];

int solve(int n, int *a, int bit){
	if(bit < 0) return a[1];
	int len[2] = {};
	for(int i = 1; i <= n; i++){
		bool k = (1 << bit) & a[i];
		if(k) a[i] -= 1 << bit;
		b[k][++len[k]] = a[i] | (1 << bit);
	}
	if(!(len[0] && len[1])) return solve(n, a, --bit);
	memcpy(a + 1, b[0] + 1, sizeof(int) * len[0]);
	memcpy(a + 1 + len[0], b[1] + 1, sizeof(int) * len[1]);
	return min(solve(len[0], a, bit - 1), solve(len[1], a + len[0], bit - 1));
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	printf("%d", solve(n, a, 29));
	return 0;
}