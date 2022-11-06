//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n;
stack<int> s;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int p = ceil(1.0*n/4);
		for(int i=1;i<=p;i++) {
			s.push(8);
		}
		for(int i=p+1;i<=n;i++) {
			s.push(9);
		}
		while(!s.empty()) {
			printf("%d", s.top());
			s.pop();
		}
		puts("");
	}
	return 0;
}