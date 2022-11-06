//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int T, n;
string s;
queue<int> a0, a1;
int a[N], tot;

int main() {
	scanf("%d", &T);
	while(T--) {
		tot = 0;
		while(!a0.empty()) a0.pop();
		while(!a1.empty()) a1.pop();
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		cin>>s;
		for(int i=0;i<n;i++) {
			int _ = s[i] - '0';
			if(_ == 0) {
				if(!a0.empty()) {
					a[i] = a0.front();
					a0.pop();
					a1.push(a[i]);
				}
				else {
					a[i] = ++tot;
					a1.push(a[i]);
				}
			}
			else {
				if(!a1.empty()) {
					a[i] = a1.front();
					a1.pop();
					a0.push(a[i]);
				}
				else {
					a[i] = ++tot;
					a0.push(a[i]);
				}
			}
		}
		printf("%d\n", tot);
		for(int i=0;i<n;i++) {
			printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}