//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, k;
string s1, s2;
queue<int> q;
stack<int> s;

int main() {
	scanf("%d", &T);
	while(T--) {
		k = 0;
		scanf("%d", &n);
		cin>>s1>>s2;
		s1 = " " + s1;
		s2 = " " + s2;
		int lst = 1;
		for(int i=1;i<=n;i++) {
			if(s1[i] == '0' && s1[i-1] != '0') {
				lst = i - 1;
			}
			if(s1[i] == '0' && (i == n || s1[i+1] != '0')) {
				if(i == 1 || lst == 0) {
					++k;
					q.push(i);
				}
				else {
					k += 2;
					q.push(lst);
					q.push(i);
				}
			}
		}
		lst = 1;
		for(int i=1;i<=n;i++) {
			if(s2[i] == '0' && s2[i-1] != '0') {
				lst = i - 1;
			}
			if(s2[i] == '0' && (i == n || s2[i+1] != '0')) {
				if(i == 1 || lst == 0) {
					++k;
					s.push(i);
				}
				else {
					k += 2;
					s.push(lst);
					s.push(i);
				}
			}
		}
		printf("%d ", k);
		while(!q.empty()) {
			printf("%d ", q.front());
			q.pop();
		}
		while(!s.empty()) {
			printf("%d ", s.top());
			s.pop();
		}
		puts("");
	}
	return 0;
}