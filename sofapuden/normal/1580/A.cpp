#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<string> v(n);
		for(auto &x : v)cin >> x;
		vector<vector<int>> pre(n,vector<int>(m,0));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				pre[i][j] = (v[i][j] - '0');
				if(i)pre[i][j]+=pre[i-1][j];
				if(j)pre[i][j]+=pre[i][j-1];
				if(i && j)pre[i][j]-=pre[i-1][j-1];
			}
		}
		ll ans = 1e9;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				for(int k = i+4; k < n; ++k){
					for(int z = j+3; z < m; ++z){
						ll cur = pre[k-1][z-1];
						cur+=pre[i][j];
						cur-=pre[i][z-1];
						cur-=pre[k-1][j];
						if(cur >= ans)break;
						ll cu2 = pre[k][z];
						if(i)cu2-=pre[i-1][z];
						if(j)cu2-=pre[k][j-1];
						if(i && j)cu2+=pre[i-1][j-1];
						cu2-=(v[i][j]-'0');
						cu2-=(v[k][j]-'0');
						cu2-=(v[i][z]-'0');
						cu2-=(v[k][z]-'0');
						cu2-=cur;
						ll cu3 = pre[k-1][z-1];
						if(i && j)cu3+=pre[i-1][j-1];
						if(i)cu3-=pre[i-1][z-1];
						if(j)cu3-=pre[k-1][j-1];
						cu3-=cur;
						if(k-i-1+z-j-1-cu3 >= ans)break;
						ans = min(ans, cur + (2*(k-i-1)+2*(z-j-1)-cu2));
					}
				}
			}
		}
		cout << ans << '\n';
	}
}