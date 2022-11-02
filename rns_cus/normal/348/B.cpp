#include<bits/stdc++.h>
using namespace std;

#define N 200020

typedef long long LL;

vector <int> v[N];
int a[N], n, x, y, sz[N];
LL mx[N], p[N], sum;
const LL INF = 1e16;

LL lcm(LL x, LL y){
	LL d = __gcd(x, y);
	if(x / d >= INF / y) return INF;
	return x / d * y;
}

void dfs(int x, int pre){
	mx[x] = INF;
	for(auto y : v[x]){
		if(y == pre) continue;
		sz[x] ++;
		dfs(y, x);
		mx[x] = min(mx[y], mx[x]);
	}

	if(sz[x] == 0){ mx[x] = a[x]; return; }

	for(auto y : v[x]){
		if(y == pre) continue;
		p[x] = lcm(p[x], p[y]);
		if(p[x] == INF){
			mx[x] = 0; p[x] = 1; return;
		}
	}

	mx[x] = mx[x] / p[x] * p[x];

	mx[x] = mx[x] * sz[x];
	p[x] = p[x] * sz[x];
}


int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
		sum += a[i];
		p[i] = 1;
	}
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	cout << sum - mx[1] << endl;
}