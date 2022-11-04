#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 101;

int t, n;
struct monster{
	int k, h;
	monster(){}
	monster(int _k, int _h) : k(_k), h(_h) {}
	bool operator<(const monster &b) const{
		return k - h < b.k - b.h;
	}
}mon[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &mon[i].k);
		for(int i = 1; i <= n; i++)
			scanf("%d", &mon[i].h);
		sort(mon + 1, mon + 1 + n);
		int l = 0, r = -1;
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			int s = mon[i].k - mon[i].h + 1;
			if(s > r){
				ans += 1ll * (r - l + 1) * (r - l + 2) / 2;
				l = s;
			}
			r = max(r, mon[i].k);
		}
		ans += 1ll * (r - l + 1) * (r - l + 2) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}