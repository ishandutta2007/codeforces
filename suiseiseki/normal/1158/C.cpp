#include <bits/stdc++.h>

using namespace std;

#define ge getchar()
#define Re read()

inline int read() {
	int t = 0, x = 0, ch;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = ge;
	return t ? -x : x;
}

const int MAXN = 500000;

struct Node {
	int id, v;

	friend bool operator < (Node a, Node b) {
		return a.v == b.v ? a.id < b.id : a.v > b.v;
	}
} St[MAXN + 1];

int p[MAXN + 1];
int S[MAXN + 1];
int res[MAXN + 1];
int top;
int n;
int P;

int main() {
	int T = Re, Err = 0;
	while(T--) {
		Err = 0;
		n = Re;
		S[top = 1] = n + 1;
		for(int i = 1; i <= n; i++) {
			p[i] = Re;
			while(S[top] <= i) top--;
			if(!Err && p[i] > S[top]) Err = 1;
			S[++top] = p[i];
			while(S[top] <= i) top--;
			St[i] = (Node) {
				i, p[i]
			};
		}
		if(Err) {
			puts("-1");
			continue;
		}
		for(int i = 1; i <= n; i++) if(p[i] != -1 && p[p[i]] == -1) St[p[i]].v = p[i] + 1;
		sort(St + 1, St + 1 + n);
		for(int i = 1; i <= n; i++) res[St[i].id] = n - i + 1;
		for(int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	}
	return 0;
}