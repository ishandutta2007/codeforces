#include <bits/stdc++.h>
using namespace std;
#define M 300001

int a[M], b[M];
map<int, int> mp;
int n,m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n ;i ++) scanf("%d", &a[i]), mp[a[i]] = 1;

    int cnt = 0;
    for(int i = 1; i <= m; i ++) {
		if(mp[i]) continue;
        m -= i;
        b[cnt ++] = i;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i ++) {
    	printf("%d ", b[i]);
    }
}