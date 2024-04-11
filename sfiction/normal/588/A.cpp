#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int m, s, ans = 0;
	scanf("%d%d", &s, &m);
	for (int t, ts, i = 1; i < n; ++i){
		scanf("%d %d", &ts, &t);
		if (m > t){
			ans += m * s;
			m = t;
			s = 0;
		}
		s += ts;
	}
	printf("%d\n", ans += m * s);
	return 0;
}