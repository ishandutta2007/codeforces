#include <bits/stdc++.h>
using namespace std;
#define M 300001

vector<int> v[M];
int st[M], en[M];
int ans[M];

int main() {
	//freopen("2.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int  i= 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		if(x > n) continue;
		v[x].push_back(i);
	}
	for(int i = 1; i <= m; i ++) scanf("%d %d", &st[i], &en[i]);
	for(int i = 1; i <= n; i ++) if(v[i].size() >= i ) {
        for(int j = 1; j <= m; j ++) {
            int x = lower_bound(v[i].begin(), v[i].end(), st[j]) - v[i].begin();
			int y = upper_bound(v[i].begin(), v[i].end(), en[j]) - v[i].begin();
			y --;
            if(y - x + 1 == i) ans[j] ++;
        }
	}
	for(int i = 1; i <= m; i ++) printf("%d\n", ans[i]);
}