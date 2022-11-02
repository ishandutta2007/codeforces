#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int n, a[15][15], c[15], t[15], now[15], on, l, ans, id[10], sum, mlt;
bool good[] = {0, 0, 0, 0, 1, 0, 0, 1, 0, 0};

void calc(){
	for(int l = 0; l < 10; l ++){
		for(int k = 0; k <= l; k ++){
			if(l == 0){
				if(k == 0)	a[k][l] = 1;
				else a[k][l] = 0;
			}
			else{
				if(k == 0)	a[k][l] = 8 * a[k][l - 1];
				else	a[k][l] = 8 * a[k][l - 1] + 2 * a[k - 1][l - 1];
			}
		}
	}
}

void Plus(int &x, int y){
	x += y;
	x %= mod;
}

void dfs(int k){
	if(k == 0){
		for(id[0] = 0; id[0] < 10; id[0] ++){
			if(t[id[0]] == 0)	continue;
			sum = 0, mlt = t[id[0]];
			t[id[0]] --;
			dfs(1);
			t[id[0]] ++;
		}
	}
	if(k == 7){
		if(sum < id[0])	{
			Plus(ans, mlt);
		}
	}
	else{
		int osum = sum, omlt = mlt;
		for(id[k] = 0; id[k] < 10; id[k] ++){
			if(t[id[k]] == 0)	continue;
			sum = osum + id[k];
			mlt = (1ll * omlt * t[id[k]]) % mod;
			t[id[k]] --;
			dfs(k + 1);
			t[id[k]] ++;
		}
	}
}

int main(){
	scanf("%d", &n);
	calc();
	on = n, l = 0;
	while(n){
		c[l ++] = n % 10;
		n /= 10;
	}
	now[l] = 0;
	for(int i = l - 1; i >= 0; i --){
		now[i] = now[i + 1] + good[c[i]];
	}
	for(int num = 0; num < 10; num ++){
		t[num] = 0;
		if(num == now[0])	t[num] ++;
		for(int i = l - 1; i >= 0; i --){
			for(int j = 0; j < c[i]; j ++){
				if(num < now[i + 1] + good[j])	continue;
				Plus(t[num], a[num - now[i + 1] - good[j]][i]);
			}
		}
	}
	t[0] --;
	ans = 0;
	sum = 0;
	dfs(0);
	cout<<ans;
}