#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E3 + 10;

int a[MAXN], b[MAXN];
int loc[MAXN];

int cnt;
int out[MAXN * MAXN][2];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		loc[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i){
		scanf("%d", &b[i]);
		a[loc[b[i]]] = i;
	}
	/*
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	puts("");
	*/

	int cost = 0;
	cnt = 0;
	for (int i = 1; i <= n; ++i){
		int u = 0;
		for (u = i; u <= n && a[u] != i; ++u);
		for (int j = u - 1; j >= i; --j)
			if (a[j] >= u){
				cost += u - j;
				out[cnt][0] = u;
				out[cnt][1] = j;
				++cnt;
				swap(a[u], a[j]);
				u = j;
				j = u;
			}
	}
	printf("%d\n%d\n", cost, cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d %d\n", out[i][0], out[i][1]);
	
	return 0;
}