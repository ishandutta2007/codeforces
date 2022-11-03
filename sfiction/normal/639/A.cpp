#include <cstdio>

const int MAXN = 15E4 + 10;

int t[MAXN];
int a[10];

int main(){
	int n, K, q;
	scanf("%d%d%d", &n, &K, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	int com, id;
	for (int i = 0; i < q; ++i){
		scanf("%d%d", &com, &id);
		if (com == 1){
			int j = K;
			for (; 0 < j && t[a[j - 1]] < t[id]; --j)
				a[j] = a[j - 1];
			a[j] = id;
		}
		else{
			bool flag = false;
			for (int i = 0; i < K; ++i)
				flag |= a[i] == id;
			puts(flag ? "YES" : "NO");
		}
	}
	return 0;
}