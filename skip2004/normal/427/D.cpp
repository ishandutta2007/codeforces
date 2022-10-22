#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
char s0[maxn];
char s1[maxn];
const int N = 2e5;


int mx[N], fa[N], c[N][26], tot, la;
inline void ins(int w){
	int p = la,now = la = ++ tot;
	mx[now] = mx[p] + 1;
	for(;p && !c[p][w];p = fa[p]) c[p][w] = now;
	if(!p) fa[now] = 1;
	else {
		int q = c[p][w];
		if(mx[p] + 1 == mx[q]) fa[now] = q;
		else {
			int x = ++ tot; fa[x] = fa[q]; mx[x] = mx[p] + 1;
			memcpy(c[x],c[q],sizeof c[x]); fa[q] = fa[now] = x;
			for(;p && c[p][w]==q;p = fa[p]) c[p][w] = x;
		}
	}
}

int c0[N];
int c1[N];
int a0[N];
int a1[N];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> s0 >> s1;
	int n0 = strlen(s0);
	int n1 = strlen(s1);
	la = tot = 1;
	for(int i = 0;i < n0;++i) ins(s0[i] - 'a'), a0[i] = la;
	la = 1;
	for(int i = 0;i < n1;++i) ins(s1[i] - 'a'), a1[i] = la;
	for(int i = 0;i < n0;++i) for(int x = a0[i];x;x = fa[x]) ++ c0[x];
	for(int i = 0;i < n1;++i) for(int x = a1[i];x;x = fa[x]) ++ c1[x];
	int ans = 1e9;
	for(int i = 2;i <= tot;++i) {
		if(c0[i] == 1 && c1[i] == 1) {
			ans = std::min(ans, mx[fa[i]] + 1);
		}
	}
	if(ans > 1e8) ans = -1;
	cout << ans << '\n';
}