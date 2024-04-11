#include<bits/stdc++.h>
using namespace std;

#define N 100010

typedef long long LL;

LL u[N];
int a[N], b[N], sb[N], mx, mn, gas[N];
int cnt, cur, n;

int main(){
	///freopen("c.in", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i ++) scanf("%I64d", u + i);

	for(cnt = 0; cnt <= n && cur < n; cnt ++){
		while(cur < n && u[cur] == (1ll << cnt)){ cur ++; a[cnt] ++; }
		if(a[cnt] == 0){ b[cnt] = n - cur; break; }
		while(cur < n && u[cur] < (1ll << (cnt + 1))){ cur ++; b[cnt] ++; }
	}

	if(b[cnt]){ puts("-1"); return 0; }

	for(int i = 1; i < cnt; i ++){
		if(a[i] > a[i-1]){ b[i] += a[i] - a[i-1];  a[i] = a[i-1]; }
	}
	for(int i = cnt; i -- ; ){
		gas[i] = gas[i+1] + (a[i] - a[i+1]) * (i + 2);
		sb[i] = sb[i+1] + b[i];
		if(a[i] < sb[i]){ puts("-1"); return 0; }
	}
	mn = mx = a[0];
	for(int i = cnt; i --; ){
		if(gas[i] >= n){
			mn = a[i+1] + (n - gas[i+1] + i + 1) / (i + 2);
			break;
		}
	}
	for(int i = mn; i <= mx; i ++) printf("%d ", i); puts("");
}