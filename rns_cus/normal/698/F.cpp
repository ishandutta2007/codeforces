#include<bits/stdc++.h>
using namespace std;

#define N 1000100
#define mod 1000000007

bitset <N> vis;
int arr[N], n;
int p[1000], cnt, cur[N], pre[N];

void get_prime(){
	for(int i = 2; i <= 1000; i ++) if(!vis[i]) {
		p[cnt ++] = i;
		for(int j = i * i; j <= N; j += i) vis[j] = true;
	}
}

int s[N], cp[N], f[N], gas[N], tot[N];
void get_seed(){
	for(int i = 1; i <= n; i ++){
		int x = i; s[i] = 1;
		if(!vis[x] && x > sqrt(n) ){
			if(x > n / 2) gas[1] ++;
			else{
				cp[i] = x;
				f[i] = n / x;
				tot[f[i]] ++;
			}
			continue;
		}
		for(int j = 0; j < cnt && p[j] <= sqrt(x); j ++){
			if(x % p[j] == 0){
				s[i] *= p[j];
				while(x % p[j] == 0) x /= p[j];
			}
		}
		if(x > sqrt(n)) cp[i] = x, f[i] = n / x;
		s[i] *= x;
		gas[s[i]] ++;
	}
}

int rp[N];
void get_mul(){
	rp[0] = 1;
	for(int i = 1; i <= n; i ++) rp[i] = 1ll * rp[i-1] * i % mod;
}

void finish(){ puts("0"); exit(0); }

int main(){
	//freopen("f2.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", arr + i);
	get_prime();
	get_seed();
	get_mul();
	for(int i = 1; i <= n; i ++){
		if(!arr[i]) continue;
		if(f[arr[i]] != f[i]) cerr << i << " " << arr[i] << endl, finish();
		if( !f[i] ){
			if(s[i] != s[arr[i]]) finish();
			gas[s[i]] --; continue;
		}
		else{
			if(s[i] > 1) gas[s[i]] --;
			if(pre[cp[arr[i]]] && pre[cp[arr[i]]] != cp[i]) finish();
			if(pre[cp[arr[i]]] == 0){ pre[cp[arr[i]]] = cp[i]; }
			if(cur[cp[i]] && cur[cp[i]] != cp[arr[i]]) finish();
			if(cur[cp[i]] == 0){ cur[cp[i]] = cp[arr[i]]; tot[f[i]] --; }
		}
	}
	long long ans = 1;
	for(int i = 1; i <= n; i ++){
		if(gas[i]){ ans = ans * rp[gas[i]] % mod; }
		if(tot[i]){ ans = ans * rp[tot[i]] % mod; }
	}
	cout << ans << endl;
}