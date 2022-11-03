#include <cstdio>
#include <cstring>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int l1 = 1, l2 = 1;
	for (int t = (n - 1) / 7; t; t /= 7, ++l1);
	for (int t = (m - 1) / 7; t; t /= 7, ++l2);
	if (l1 + l2 > 7)
		puts("0");
	else{
		int cnt[7], s = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i){
			for (int t = i, ti = 0; ti++ < l1; ++cnt[t % 7], t /= 7);
			for (int j = 0; j < m; ++j){
				for (int t = j, ti = 0; ti++ < l2; ++cnt[t % 7], t /= 7);
				bool flag = true;
				for (int k = 0; k < 7; ++k)
					flag &= cnt[k] < 2;
				s += flag;
				for (int t = j, ti = 0; ti++ < l2; --cnt[t % 7], t /= 7);
			}
			for (int t = i, ti = 0; ti++ < l1; --cnt[t % 7], t /= 7);
		}
		printf("%d\n", s);
	}
	return 0;
}