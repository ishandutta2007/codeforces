#include <bits/stdc++.h>
#define int ull
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

map <int, int> wxw1, ans, vis;
char Name[10005][10];
int Len[10005];
char c[10]; int len;
int n, m;

#undef int
int main() {
#define int ull
	cin >> n;
	for(register int i = 1; i <= n; i++) {
		vis.clear();
		scanf("%s", c + 1);
		len = strlen(c + 1);
		Len[i] = len;
		for(register int j = 1; j <= len; j++) {
			Name[i][j] = c[j];
			int now = 0;
			for(register int k = j; k <= len; k++) {
				now = (now * 233 + c[k]);
				if(vis.count(now)) continue;
				vis[now] = 1; wxw1[now]++;
				if(!ans.count(now)) {
					ans[now] = i;
				}
			}
		}
	}
	cin >> m;
	for(register int i = 1; i <= m; i++) {
		scanf("%s", c + 1);
		int now = 0; len = strlen(c + 1);
		for(register int j = 1; j <= len; j++) now = (now * 233 + c[j]);
		if(!wxw1.count(now)) puts("0 -");
		else {
			print(wxw1[now], ' ');
			int Ans = ans[now];
			for(register int j = 1; j <= Len[Ans]; j++) putchar(Name[Ans][j]);
			putchar('\n');
		} 
	}
	return 0;
}