#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define TOP_N 100005

int n, a[TOP_N], L[TOP_N], d[TOP_N], rtc[TOP_N], tc[TOP_N], cnt, mlt[TOP_N][20], ans;

void calc(){
	for(int k = 1; k < TOP_N; k ++){
		for(int i = 0; i < 20; i ++){
			if(i == 0)	mlt[k][i] = k;
			else	mlt[k][i] = (1ll * mlt[k][i - 1] * mlt[k][i - 1]) % mod;
		}
	}
	ans = 0;
}

int Pow(int x, int y){
	if(x == 0)	return y ? 0 : 1;
	int rtn = 1;
	while(y){
		int k = 0, ny = y;
		while(ny % 2 == 0)	ny /= 2, k ++;
		rtn = (1ll * rtn * mlt[x][k]) % mod;
		y -= y & (-y);
	}
	return rtn;
}

int main(){
	//freopen("sample.in", "r", stdin);
	calc();
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)	d[i] = 0;
	for(int i = 0; i < n; i ++)	scanf("%d", &a[i]), d[a[i]] ++;
	L[1] = 0;
	for(int i = 2; i <= TOP_N; i ++) L[i] = L[i - 1] + d[i - 1];
	for(int k = 1; k <= TOP_N; k ++){
		d[-1] = 0;
		cnt = 0;
		for(int i = 1; i * i <= k; i ++)	if(k % i == 0)	d[cnt ++] = i;
		if(d[cnt - 1] * d[cnt - 1] != k){
			for(int i = cnt; i < 2 * cnt; i ++)	d[i] = k / d[2 * cnt - 1 - i];
			cnt = 2 * cnt;
		}
		else{
			for(int i = cnt; i < 2 * cnt - 1; i ++)	d[i] = k / d[2 * cnt - 2 - i];
			cnt = 2 * cnt - 1;
		}
		d[cnt] = TOP_N;
		int more = 1;
		for(int i = 0; i <= cnt; i ++){
			more = (1ll * more * Pow(i, L[d[i]] - L[d[i - 1]])) % mod;
		}
		ans = (1ll * ans + more) % mod;
		cnt --;
		d[cnt] = TOP_N;
		more = 1;
		for(int i = 0; i <= cnt; i ++){
			more = (1ll * more * Pow(i, L[d[i]] - L[d[i - 1]])) % mod;
		}
		ans = (1ll * ans + mod - more) % mod;
	}
	printf("%d", ans);
}