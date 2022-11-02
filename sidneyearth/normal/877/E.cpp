#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200010;
struct Edge{
	int u, v, nxt;
}e[2 * maxn];
int head[maxn], e_cnt, a[maxn], clk, ql, qr, l[maxn], r[maxn], f[4 * maxn][2], setv[4 * maxn], tid[maxn];
void Add(int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
void DFS(int u, int fa){
	l[u] = ++clk;
	tid[clk] = u;
	for(int id = head[u]; id != -1; id = e[id].nxt)
		if(fa != e[id].v) DFS(e[id].v, u);
	r[u] = clk + 1;
}
void Maintain(int o, int l, int r){
	if(r - l > 1){
		f[o][0] = f[2 * o][0] + f[2 * o + 1][0];
		f[o][1] = f[2 * o][1] + f[2 * o + 1][1];
	}
	else{
		f[o][0] = (a[tid[l]] == 0);
		f[o][1] = (a[tid[l]] == 1);
	}
	if(setv[o])
		swap(f[o][0], f[o][1]);
}
void Set(int o, int l, int r){
//	printf("l:%d r:%d\n", l, r);
	if(ql <= l && r <= qr)
		setv[o] ^= 1;
	else{
		int mid = (l + r) / 2;
		if(ql < mid) Set(2 * o, l, mid);
		if(mid < qr) Set(2 * o + 1, mid, r);
	}
	Maintain(o, l, r);
}
int Query(int o, int l, int r, int t){
//	printf("l:%d r:%d\n", l, r);
	if(ql <= l && r <= qr) return f[o][1^t];
	else{
		int mid = (l + r) / 2, rnt = 0;
		if(ql < mid) rnt += Query(2 * o, l, mid, t ^ setv[o]);
		if(mid < qr) rnt += Query(2 * o + 1, mid, r, t ^ setv[o]);
		return rnt;
	}
}
void Build(int o, int l, int r){
	if(r - l > 1){
		int mid = (l + r) / 2;
		Build(2 * o, l, mid);
		Build(2 * o + 1, mid, r);
	}
	Maintain(o, l, r);
}
void Print(int o, int l, int r){
	if(r - l > 1){
		int mid = (l + r) / 2;
		Print(2 * o, l, mid);
		Print(2 * o + 1, mid, r);
	}
	printf("o:%d l:%d r:%d f[0]:%d f[1]:%d set:%d\n", o, l, r, f[o][0], f[o][1], setv[o]);
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		head[i] = -1;
	e_cnt = 0;
	for(int i = 2; i <= n; i++){
		int t; scanf("%d", &t);
		Add(i, t);
		Add(t, i);
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	clk = 0;
	DFS(1, 0);
	Build(1, 1, n + 1);
//	Print(1, 1, n + 1);
	int m; scanf("%d", &m);
	for(int i = 0; i < m; i++){
		char s[10]; int t;
		scanf("%s%d", s, &t);
		ql = l[t]; qr = r[t];
		if(s[0] == 'p'){
			Set(1, 1, n + 1);
//			Print(1, 1, n + 1);
		}
		else
			printf("%d\n", Query(1, 1, n + 1, 0));
	}
	return 0;
}