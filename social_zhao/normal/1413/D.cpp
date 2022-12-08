#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
struct Operation {
	char opt;
	int val;
} t[N]; 
int n, ans[N];
priority_queue<int> q;

int main() {
	n = get();
	for(int i = 1; i <= n << 1; i++) {
		scanf("%s", &t[i].opt);
		if(t[i].opt == '-') t[i].val = get();
	}
	for(int i = n << 1; i >= 1; i--) {
		if(t[i].opt == '-') {
			if(q.size() && -q.top() < t[i].val) return 0 * printf("NO\n");
			q.push(-t[i].val);
		}
		else {
			if(q.empty()) return 0 * printf("NO\n");
			ans[i] = -q.top(); q.pop();
		}
	}
	printf("YES\n");
	for(int i = 1; i <= n << 1; i++) if(ans[i]) printf("%d ", ans[i]);
	return 0;
}