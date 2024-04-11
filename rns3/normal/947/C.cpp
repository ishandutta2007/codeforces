#include <bits/stdc++.h>
using namespace std;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}

inline int getint(){
  int x;
  char c=nc(),b=1;
  if(c == -1)
	return 0;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
  return x;
}


const int K = 30;

const int L = 10;

const int INF = 1 << L;
map <int, int> mp[K];
int MP[K][1<<(K-L)];

#define N 303030

int a[N], b[N], n;
int ans[N];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("w.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) a[i] = getint();
	for (int i = 1; i <= n; i ++) b[i] = getint();
	for (int i = 1; i <= n; i ++) {
		int x = b[i];
		for (int k = 0; k < L; k ++) {
			mp[k][x] ++;
			x >>= 1;
		}
		for (int k = L; k < K; k ++) {
			MP[k][x] ++;
			x >>= 1;
		}
	}
	for (int i = 1; i <= n; i ++) {
		int x = a[i];
		int rlt = 0;
		for (int k = K - 1, tmp; k >= L; k --) {
			tmp = (rlt ^ x) >> k;
			if (MP[k][tmp] == 0) rlt ^= (1 << k);
		}
		for (int k = L - 1, tmp; k >= 0; k --) {
			tmp = (rlt ^ x) >> k;
			if (!mp[k].count(tmp) || mp[k][tmp] == 0) rlt ^= (1 << k);
		}
		ans[i] = rlt;
		x ^= rlt;
		for (int k = 0; k < L; k ++) {
			mp[k][x] --;
			x >>= 1;
		}
		for (int k = L; k < K; k ++) {
			MP[k][x] --;
			x >>= 1;
		}
	}
	for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
	puts("");

	return 0;
}