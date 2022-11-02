#include<bits/stdc++.h>
using namespace std;

#define N 100010
int n, m, a[N], ans;

bool can(int t, int cur, int id, int d){
	for(int i = id; i < n; i ++){
		if(cur >= a[i]) cur = a[i] + d + 1;
		else{
			if(a[i] > cur + d) return 0;
			if(i < n - 1 && a[i+1] <= cur + d && a[i+1] != a[i] + 1) cur = a[i ++] + d + 1;
			else cur = a[i] + 1;
		}
	}return cur >= a[n] - t;
}

bool OK(int d){
	if(a[1] > a[0] + 2 * d + 1) return 0;
	if(can(0, a[0] + d + 1, 1, d)) return 1;
	if(a[1] < a[0] + d){
		if(can(d - a[1] + a[0], a[0] + d + 1, 2, d)) return 1;
	}return 0;
}

int calc(){
	int l = -1, r = m;
	while( l < r - 1){
		int md = l + r >> 1;
		if(OK(md)) r = md;
		else l = md;
	} return r;
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i ++) scanf("%d", a + i); a[n] = a[0] + m;
	ans = calc();
	reverse(a, a + n + 1);
	for(int i = 0; i <= n; i ++) a[i] = -a[i];
	printf("%d\n", min(ans, calc()));
}