#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n;
int a[N], b[N], top;

queue<int> q[N]; 

void solve() {
	n = get();
	for(int i = 0; i <= n; i++) {
		while(q[i].size()) q[i].pop();
	}
	top = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), q[a[i]].push(i);
	int mx = 0, tot = n, mp = 0;
	for(int i = 0; i <= n; i++) {
		if(q[i].size()) mx = i + 1, mp = max(mp, q[i].front());
		else break;
	}
	while(tot && mx) {
		b[++top] = mx;
		int nmx = 0, nmp = mp, flag = 1;
		for(int i = 0; i < mx; i++) {
			while(q[i].size() && q[i].front() <= mp) 
				q[i].pop(), --tot;
			if(q[i].size() && flag) nmx = i + 1, nmp = max(nmp, q[i].front());
			else flag = 0;
		}
		mx = nmx, mp = nmp;
	}
	for(int i = 0; i <= n; i++) {
		while(q[i].size() && q[i].front() <= mp) q[i].pop(), --tot;
	}
	printf("%d\n", top + tot);
	for(int i = 1; i <= top; i++) printf("%d ", b[i]);
	for(int i = 1; i <= tot; i++) printf("0 ");
	printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}