#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define N 11
#define inf 43046721
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int n, x, y, ans;
int a[N], b[N];

short int num(int i){
	int rlt  = 0;
	while(i) rlt += (i%9), i/=9;
	return rlt;
}

int main(){
	scanf("%d %d %d", &n, &x, &y);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);

	int r1 = a[1] / y + 1, r2 = a[n] / y + 1;

	if(n == 3){
		int r = max(r1, r2);
		r = max(a[2] / x + 1, r);
		printf("%d\n", r);
		for(int i=0; i<r; i++) printf("2 "); puts("");
		return 0;
	}

	ans = r1 + r2;
	a[1] -= y * r1, a[2] -= x * r1, a[3] -= y *r1;
	a[n] -= y * r2, a[n-1] -= x * r2, a[n-2] -= y * r2;

	int st = 1, en = n;
	while(a[st] < 0) st ++;
	while(a[en] < 0) en --;

	int lim = 1;
	for(int i=st; i<=en; i++) lim *= 9;

	int bits = lim - 1, mn = inf;
	for(int i=0; i<lim; i++) {
		int NUM = num(i);
		if(NUM >= mn) continue;
		int j = i;
		for(int k=st; k<=en; k++) b[k] = a[k];
		for(int k=st; k<=en; k++){
			int r = j % 9;
			j /= 9;
			b[k] -= x * r, b[k-1] -= y * r, b[k+1] -= y * r;
		}
		bool fg = 1;
		for(int k=st; k<=en; k++) if(b[k] >= 0) {fg = 0; break;}
		if(fg) bits = i, mn = NUM;
	}
	ans += mn;

	printf("%d\n", ans);

	for(int i=0; i<r1; i++) printf("2 ");
	for(int i=0; i<r2; i++) printf("%d ", n-1);

	for(int k=st; k<=en; k++){
		int r = bits % 9;
		for(int j=0; j<r; j++) printf("%d ", k);
		bits /= 9;
	}
	puts("");
}