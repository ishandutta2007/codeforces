//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a;
bool book[55];
queue<int> q;

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(book, 0, sizeof(book));
		scanf("%d", &n);
		for(int i=1;i<=(n<<1);i++) {
			scanf("%d", &a);
			book[a] ^= 1;
			if(!book[a]) {
				q.push(a);
			}
		}
		while(!q.empty()) {
			printf("%d ", q.front());
			q.pop();
		}
		puts("");
	}
	return 0;
}