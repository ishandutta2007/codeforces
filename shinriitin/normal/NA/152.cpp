#include <bits/stdc++.h>

#define SZ(x) ((int)((x).size()))

const int max_N = (int)3e5 + 21;

int n, x1, x2, c[max_N];

std::pair<int, int> p[max_N];

std::vector<int> ans[2];

bool solve(int x1, int x2, int n, bool flag){
	ans[0].clear(), ans[1].clear();
	int i = n;
	for(;i;--i){
		if(1ll*p[i].first*(n-i+1)>=x1){
			for(int j=i;j<=n;++j){
				ans[flag].push_back(p[j].second);
			}
			break;
		}
	}
	n = --i;
	for(;i;--i){
		if(1ll*p[i].first*(n-i+1)>=x2){
			for(int j=i;j<=n;++j){
				ans[flag^1].push_back(p[j].second);
			}
			break;
		}
	}
	return SZ(ans[flag]) && SZ(ans[flag^1]);
}

int main(){
	scanf("%d%d%d", &n, &x1, &x2);
	for(int i=1;i<=n;++i){
		scanf("%d", c+i);
		p[i] = {c[i], i};
	}
	std::sort(p+1, p+1+n);
	if(solve(x1, x2, n, 0) || solve(x2, x1, n, 1)){
		puts("Yes");
		printf("%d %d\n", SZ(ans[0]), SZ(ans[1]));
		for(int i=0;i<2;++i){
			std::sort(ans[i].begin(), ans[i].end());
			for(auto&x:ans[i]) printf("%d ", x);
			puts("");
		}
	}
	else puts("No");
	return 0;
}