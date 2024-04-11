#include<bits/stdc++.h>
#define InRange(x,l,r) (l <= x && x <= r)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 205;
int n, k, vis[N], l[N], r[N], bin[N], top; 

void solve() {
	n = get(), k = get(), top = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= k; i++) l[i] = get(), r[i] = get(), vis[l[i]] = vis[r[i]] = 1;
	for(int i = 1; i <= 2 * n; i++) if(!vis[i]) bin[++top] = i;
	for(int i = 1; i <= n - k; i++) l[k + i] = bin[i], r[k + i] = bin[i + n - k];
	for(int i = 1; i <= n; i++) if(l[i] > r[i]) swap(l[i], r[i]);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			if((InRange(l[i], l[j], r[j]) && !InRange(r[i], l[j], r[j])) || (InRange(r[i], l[j], r[j]) && !InRange(l[i], l[j], r[j])))
				++ans;
	printf("%d\n", ans);
}

int main() {
	int t = get();
	while(t--) solve();
	return 0; 
}