#include <cstdio>

const int MAXN = 1E3 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = 0, cnt = 0;
	for (; ; ++ans){
		bool flag = false;
		if (ans & 1){
			for (int i = n; i > 0; --i)
				if (a[i] >= 0 && a[i] <= cnt)
					a[i] = -1, ++cnt, flag = true;
		}
		else{
			for (int i = 1; i <= n; ++i)
				if (a[i] >= 0 && a[i] <= cnt)
					a[i] = -1, ++cnt, flag = true;
		}
		if (!flag)
			break;
	}
	printf("%d\n", ans - 1);
	return 0;
}