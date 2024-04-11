#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[1<<19][19], vi[1<<19][19], gr[19][19];
int n, m;

ll fin(int mask, int x, int st){
	if(vi[mask][x] == st+1)return dp[mask][x];
	ll ret = 0;
	for(int i = st; i < n; ++i){
		if(gr[x][i]){
			if(i == st){
				if(mask != ((1 << st) + (1<<x)))ret++;

			}
			else{
				if(mask & (1<<i)) continue;
				ret+=fin(mask | (1 << i),i,st);
			}
		}
	}
	vi[mask][x] = st+1;
	return dp[mask][x] = ret;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < (1<<n); ++i)for(int j = 0; j < n; ++j)dp[i][j] = 0;
	memset(gr,0,sizeof gr);
	memset(vi,0,sizeof vi);
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		gr[a][b] = 1;
		gr[b][a] = 1;
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans+=fin(1<<i,i,i);
	}
	cout << ans/2 << '\n';
}