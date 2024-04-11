#include <bits/stdc++.h>

using ll = long long;

const int max_N = (int)1e5 + 21;

const int max_M = 60;

int hbt(ll b){
	for(int i=max_M-1;~i;--i)
		if((b>>i)&1) return i;
	return -1;
}

int n, m;

ll a, b[max_N], ans[max_N];

std::queue<ll> q[max_M];

ll poll(std::queue<ll>&q){
	ll x = q.front();
	return q.pop(), x;
}

void dfs(int bit, ll&a){
	if(bit < 0) return;
	if(!bit){
		if((a&1) && !q[0].empty()){
			ll x = poll(q[0]);
			ans[++m] = x, a ^= x;
		}
		return;
	}
	if(!((a>>bit)&1) || q[bit].empty()){
		dfs(bit-1, a);
	}
	else{
		dfs(bit-1, a);
		ll x = poll(q[bit]);
		ans[++m] = x, a ^= x;
		dfs(bit-1, a);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;++i){
		scanf("%lld", b+i);
		a ^= b[i];
		q[hbt(b[i])].push(b[i]);
	}
	dfs(hbt(a), a);
	if(m != n) return puts("No"), 0;
	puts("Yes");
	for(int i=n;i;--i){
		printf("%lld%c", ans[i], " \n"[i==1]);
	}
	return 0;
}