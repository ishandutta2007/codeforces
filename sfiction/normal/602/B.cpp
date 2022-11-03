#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int now = -1, pre = -1;
	int loc = 0, len = 0;
	int ans = 0;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		if (t != now){
			if (pre != -1 && t != pre)
				len = i - loc;
			pre = now;
			now = t;
			loc = i;
		}
		if (ans < ++len)
			ans = len;
	}
	printf("%d\n", ans);
	return 0;
}