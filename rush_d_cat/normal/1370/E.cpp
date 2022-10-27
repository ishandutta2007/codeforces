#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int n;
char s[N], t[N];
const int inf = 1e9;
set<int> st[2];
bool solve(){
	assert(st[0].size() == st[1].size());
	//printf("%d %d\n", st[0].size(), st[1].size());
	if (st[0].size() == 0 || st[1].size() == 0) return 0;
	/*
	printf("0\n");
	for (auto x: st[0]) printf("%d ", x); printf("\n");
	printf("1\n");
	for (auto x: st[1]) printf("%d ", x); printf("\n");
*/
	if(*st[0].begin() < *st[1].begin()) {
		int now = *st[0].begin();
		if (now == inf) return 0;
		while (now < inf) {
			int d1, d2;
			d1 = now;
			now = *st[1].lower_bound(now);
			d2 = now;

			if (now == inf) break;
			else {
				st[0].erase(d1);
				st[1].erase(d2);
			}
			now = *st[0].lower_bound(now);
		}
	} else {
		int now = *st[1].begin();
		if (now == inf) return 0;
		//printf("now = %d\n", now);
		while (now < inf) {
			int d1, d2;
			d1 = now;
			now = *st[0].lower_bound(now);
			d2 = now;

			//printf("d1 = %d, d2 = %d\n", d1, d2);
			if (now == inf) break;
			else {
				st[1].erase(d1);
				st[0].erase(d2);
			}

			now = *st[1].lower_bound(now);
		}		
	}
	return 1;
}

int main() {
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i++)if(s[i]!=t[i]){
		//printf("i=%d, %d\n", t[i]-'0');
		st[t[i]-'0'].insert(i);
	}
	st[0].insert(inf); st[1].insert(inf);
	//printf("%d %d\n", st[0].size(), st[1].size());
	if(st[0].size() != st[1].size()) {
		return !printf("-1\n");
	}
	int ans = 0;
	while(solve()) ans ++;
	printf("%d\n", ans);
}