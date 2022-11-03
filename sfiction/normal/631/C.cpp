#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10, MAXM = 2E5 + 10;

int a[MAXN], b[MAXN];
int que[MAXM], type[MAXM];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int top = -1;
	for (int j = 0; j < m; ++j){
		scanf("%d%d", &type[j], &que[j]);
		for (; 0 <= top && que[top] <= que[j]; --top);
		que[++top] = que[j];
		type[top] = type[j];
	}

	que[top + 1] = 0;
	for (int i = 1; i <= que[0]; ++i)
		b[i] = a[i];
	sort(b + 1, b + que[0] + 1);
	int l = 1, r = que[0];
	for (int i = 0; i <= top; ++i){
		int len = que[i] - que[i + 1];
		if (type[i] == 1){
			for (int j = 0; j < len; ++j)
				a[que[i] - j] = b[r--];
		}
		else{
			for (int j = 0; j < len; ++j)
				a[que[i] - j] = b[l++];
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], "\n "[i < n]);

	return 0;
}