#include<bits/stdc++.h>
using namespace std;

struct update{
	int L, R, val;
};

vector <update> v[7010];
vector <int> visit;
bool vis[1000100];
int n, m;

int main(){
	///freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int level, L, R, val, type, ans;
	for(int step = 1; step <= m; step ++){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d %d %d %d", &level, &L, &R, &val);
			v[level].push_back({L, R, val});
		}
		else{
			ans = 0;
			visit.clear();
			scanf("%d %d", &level, &L);
			R = L;
			for(; level <= n; level ++){
				for(update y : v[level]){
					if(vis[y.val]) continue;
					if(L <= y.R && R >= y.L){
						vis[y.val] = 1;
						ans ++;
						visit.emplace_back(y.val);
					}
				}
				if(L > 1) L += 32 - __builtin_clz(L-1);
				R += 32 - __builtin_clz(R);
			}
			for(auto x : visit) vis[x] = false;
			printf("%d\n", ans);
		}
	}
}