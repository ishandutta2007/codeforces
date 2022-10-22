#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
using namespace std;

map <int, bool> mrk;
queue <int> que;
stack <int> stk;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i++) {
		int id;
		scanf("%d", &id);
		if (mrk[id]) continue;
		if (que.size() == k) {
			mrk[que.front()] = 0;
			que.pop();
		}
		que.push(id);
		mrk[id] = 1;
	}
	printf("%d\n", que.size());
	while (!que.empty()) {
		stk.push(que.front());
		que.pop();
	}
	while (!stk.empty()) {
		printf("%d ", stk.top());
		stk.pop();
	}
	return 0;
}