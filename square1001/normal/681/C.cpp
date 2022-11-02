#include <queue>
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;
int q, x, cnt, v[300009]; char r[300009][12], c[12];
int main() {
	scanf("%d", &q);
	priority_queue<int, vector<int>, greater<int> > que;
	while (q--) {
		scanf("%s %d", &c, &x);
		if (c[0] == 'i') {
			v[cnt] = x; strcpy(r[cnt++], "insert");
			que.push(x);
		}
		else if (c[0] == 'r') {
			if (que.empty()) strcpy(r[cnt++], "insert"), que.push(0);
			strcpy(r[cnt++], "removeMin");
			que.pop();
		}
		else {
			while (!que.empty() && que.top() < x) {
				strcpy(r[cnt++], "removeMin");
				que.pop();
			}
			if (que.empty() || que.top() != x) {
				v[cnt] = x; strcpy(r[cnt++], "insert");
				que.push(x);
			}
			v[cnt] = x; strcpy(r[cnt++], "getMin");
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) printf(r[i][0] == 'r' ? "%s\n" : "%s %d\n", r[i], v[i]);
	return 0;
}