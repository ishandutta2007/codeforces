#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, a[N], aid[N], b[N], bid[N], invb[N];
bool canwin[N];

bool cmpa(const int x, const int y){
	return a[x] < a[y];
}

bool cmpb(const int x, const int y){
	return b[x] < b[y];
}

int main(){
	scanf("%d", &t);
	while(t--){
		memset(canwin + 1, 0, sizeof(bool) * n);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			aid[i] = i;
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &b[i]);
			bid[i] = i;
		}
		sort(aid + 1, aid + 1 + n, cmpa);
		sort(bid + 1, bid + 1 + n, cmpb);
		for(int i = 1; i <= n; i++)
			invb[bid[i]] = i;
		int p = n;
		for(int i = n; i >= p; i--)
			p = min(p, invb[aid[i]]);
		for(int i = n; i >= p; i--)
			canwin[aid[i]] = true;
		for(int i = 1; i <= n; i++)
			putchar(canwin[i] + '0');
		putchar('\n');
	}
	return 0;
}