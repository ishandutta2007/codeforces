#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 15;
int c[N], n, m;
struct State {
	int a[N], sum;
	State() { sum = 0, memset(a, 0, sizeof(a)); }
	bool operator <(State b) const { 
		if(sum == b.sum) {
			for(int i = 1; i <= n; i++) 
				if(a[i] < b.a[i]) return 1;
				else if(a[i] > b.a[i]) return 0;
			return 0;
		}
		return sum < b.sum; 
	}
};
vector<int> a[N];
priority_queue<State> q;
map<State, int> ban, vis;

int main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		c[i] = get();
		a[i].push_back(0);
		for(int j = 1; j <= c[i]; j++) a[i].push_back(get());
	}
	m = get();
	for(int i = 1; i <= m; i++) {
		State now;
		for(int j = 1; j <= n; j++) 
			now.a[j] = get(), now.sum += a[j][now.a[j]];
		ban[now] = 1;
	}
	State st;
	for(int i = 1; i <= n; i++) st.a[i] = c[i], st.sum += a[i][c[i]];
	q.push(st);
	while(q.size()) {
		State u = q.top(); q.pop();
		if(!ban[u]) {
			for(int i = 1; i <= n; i++) printf("%d ", u.a[i]);
			return 0;
		}
		for(int i = 1; i <= n; i++) {
			if(u.a[i] == 1) continue;
			State v = u;
			v.sum -= a[i][v.a[i]], v.a[i]--, v.sum += a[i][v.a[i]];
			if(!vis[v]) q.push(v), vis[v] = 1;
		}
	}
	return 0;
}