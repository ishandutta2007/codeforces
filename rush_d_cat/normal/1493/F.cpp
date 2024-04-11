#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1001;
int n, m;
int ask(int h, int w, int i1, int j1, int i2, int j2) {
	printf("? %d %d %d %d %d %d\n", h, w, i1, j1, i2, j2);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}
int ask_col(int l,int len) {
	return ask(n,len,1,l,1,l+len);
}


int ask_row(int l,int len) {
	return ask(len,m,l,1,l+len,1);
}

int solve(int l,int r,int x,string tp) {
	int len = (r-l+1);
	if (len % x) return 0;
	int seglen = len / x;
	if(x==2) {
		int flag = (tp == "col") ? ask_col(l,seglen) : ask_row(l,seglen);
		return flag == true ? solve(l, l+seglen-1, x, tp) + 1 : 0;
	}
	int flag = (tp=="col"?ask_col(l, seglen * (x/2)):ask_row(l, seglen * (x/2))) & (tp=="col"?ask_col(l + seglen, seglen * (x/2)):ask_row(l + seglen, seglen * (x/2)));
	return flag == true ? solve(l, l+seglen-1, x, tp) + 1 : 0;
}
int prime[N], vis[N];

void init() {
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		prime[++prime[0]] = i;
		for (int j = i + i; j < N; j += i) {
			vis[j] = 1;
		}
	}
}
int main() {
	init();
	scanf("%d%d", &n,&m);
	int ans_n = n, ans_m = m;
	for (int i = 1; i <= prime[0]; i ++) {
		int x = prime[i];
		if (n % x == 0) {
			int c = solve(1, n, x, "row"); 
			while (c --) ans_n /= x;
		}
		if (m % x == 0) {
			int c = solve(1, m, x, "col");
			while (c --) ans_m /= x; 
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if((n%i==0) && (i%ans_n==0) && (m%j==0) && (j%ans_m==0))cnt++;
	printf("! %d\n", cnt);
	fflush(stdout);
}