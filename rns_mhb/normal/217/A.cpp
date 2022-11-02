#include<bits/stdc++.h>
using namespace std;
#define N 2010

int rt[N];

int findrt(int x) {
	if (rt[x] != x) rt[x] = findrt(rt[x]);
	return rt[x];
}

bool vis[N];
int n;

int main() {
	for (int i = 1; i <= 2000; i ++) rt[i] = i;
	scanf("%d", &n);
	int x,  y;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &x, &y);
		y += 1000;
		vis[x] = vis[y] = 1;
		int xx =  findrt(x), yy = findrt(y);
		if (xx != yy) {
			ans --;
			rt[xx] = yy;
		}
	}
	for (int i = 1; i <= 2000; i ++) ans += vis[i];
	cout<<ans - 1<<endl;
}