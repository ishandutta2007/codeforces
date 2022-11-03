#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

map<ll, ll> lst;

void update(ll u, ll v, int c){
	while (u != v){
		if (u < v)
			swap(u, v);
		lst[u] += c;
		u >>= 1;
	}
}

ll count(ll u, ll v){
	ll ret = 0;
	while (u != v){
		if (u < v)
			swap(u, v);
		ret += lst[u];
		u >>= 1;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int com, c;
	ll u, v;
	for (int i = 0; i < n; ++i){
		scanf("%d%I64d%I64d", &com, &u, &v);
		if (com == 1){
			scanf("%d", &c);
			update(u, v, c);
		}
		else
			printf("%I64d\n", count(u, v));
	}
	return 0;
}