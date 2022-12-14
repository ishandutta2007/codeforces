#include <bits/stdc++.h>

using namespace std;

#define N 200005
#define M 400005

int u[M] , v[M] , fa[N] , es[N] , et[N] , ans[N];
int s , t , ds , dt , n , m , ns , nt , chose;
bool bs[N] , bt[N] , vis[N];

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	n = read() , m = read();
	for (int i = 1 ; i <= m ; i ++) u[i] = read() , v[i] = read();
	for (int i = 1 ; i <= n ; i ++) fa[i] = i;
	s = read() , t = read() , ds = read() , dt = read();
	for (int i = 1 ; i <= m ; i ++) {
		if (u[i] == s || u[i] == t || v[i] == s || v[i] == t) continue;
		int f1 = find(u[i]) , f2 = find(v[i]);
		if (f1 != f2) fa[f1] = f2 , ans[++ ans[0]] = i;
	}
	for (int i = 1 ; i <= m ; i ++) {
		int f1 = find(u[i]) , f2 = find(v[i]);
		if (f1 == s && f2 == t || f1 == t && f2 == s) {
			chose = i;
			continue;
		}
		if (f2 == s) swap(f1 , f2);
		if (f1 == t) swap(f1 , f2);
		if (f1 == s) bs[f2] = 1 , es[f2] = i;
		if (f2 == t) bt[f1] = 1 , et[f1] = i;
	}
	int i;
	for (i = 1 ; i <= n && (bs[i] == 0 || bt[i] == 0 ) ; i ++);
	ns = nt = 1;
	if (i <= n) {
		ans[++ ans[0]] = es[i];
		ans[++ ans[0]] = et[i];
		vis[i] = 1;
	}else ans[++ ans[0]] = chose;
	for (i = 1 ; i <= n ; i ++) {
		int f1 = find(i);
		if (vis[f1]) continue;
		if (bs[f1] && bt[f1]) continue;
		if (bs[f1]) ns ++ , ans[++ ans[0]] = es[f1];
		if (bt[f1]) nt ++ , ans[++ ans[0]] = et[f1];
		if (ns > ds || nt > dt) return puts("No") , 0;
		vis[f1] = 1;
	}
	for (i = 1 ; i <= n ; i ++) {
		int f1 = find(i);
		if (vis[f1]) continue;
		if (ns < ds)  ns ++ , ans[++ ans[0]] = es[f1];
		else  nt ++ , ans[++ ans[0]] = et[f1];
		if (ns > ds || nt > dt) return puts("No") , 0;
		vis[f1] = 1;
	}puts("Yes");
	for (i = 1 ; i <= ans[0] ; i ++) printf("%d %d\n" , u[ans[i]] , v[ans[i]]);
	return 0;
}