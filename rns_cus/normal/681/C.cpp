#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define M 2000010
int cnt, val[M], type[M];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, x;
	scanf("%d", &n);
	char s[100];
	multiset <int> setv;

	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		if (s[0] == 'i') {
			scanf("%d", &x); setv.insert(x);
			//printf("%s %d\n", s, x);
			type[cnt] = 1, val[cnt++] = x;
		}
		else if (s[0] == 'r') {
			if (setv.empty()) {
				type[cnt] = 1, val[cnt++] = -INF;
				//printf("insert %d\n", -INF);
				setv.insert(-INF);
			}
			//puts(s);
			type[cnt++] = 2;
			setv.erase(setv.begin());
		}
		else {
			scanf("%d", &x);
			while (!setv.empty() && *setv.begin() < x) {
				type[cnt++] = 2;//puts("removeMin");
				setv.erase(setv.begin());
			}
			if (setv.empty() || *setv.begin() > x) {
				type[cnt] = 1, val[cnt++] = x;
				setv.insert(x);
				//printf("insert %d\n", x);
			}
			type[cnt] = 3, val[cnt++] = x;
			//printf("%s %d\n", s, x);
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		if (type[i] == 1) {
			printf("insert %d\n", val[i]);
		}
		else if (type[i] == 2) puts("removeMin");
		else {
			printf("getMin %d\n", val[i]);
		}
	}
}