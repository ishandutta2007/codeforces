#include <cstdio>
#include <iostream>
#define lowbit(i) (i&-i)
using namespace std;
const int MAXN = 1e5 + 1, MAXS = 1e6 + 3;

int n, m, last, now, r[MAXN];
long long ans;

int tree[MAXS];
void add(int i){
	while(i < MAXS){
		tree[i]++;
		i += lowbit(i);
	}
}

int sum(int i){
	int ret = 0;
	while(i){
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int l = last = 1e6;
		scanf("%d", &m);
		while(m){
			m--;
			scanf("%d", &now);
			if(last < now){
				l = -1;
				r[i] = 1e6 + 1;
				break;
			}
			l = min(l, now);
			r[i] = max(r[i], now);
			last = now;
		}
		while(m--) scanf("%d", &now);
		add(l + 2);
	}
	for(int i = 1; i <= n; i++)
		ans += sum(++r[i]);
	printf("%lld", ans);
	return 0;
}