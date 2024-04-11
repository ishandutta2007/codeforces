#include<bits/stdc++.h>
using namespace std;

#define N 100010

vector <int> v[N];
int a[N], b[N], c[N], n;

int dp[2020][2020], mx, bb[N], cc[N];
const int INF = 1e9;

int main(){

///	freopen("a.in", "r", stdin);

	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
		if(a[i] < 0) a[i] = - a[i];
		v[a[i]].push_back(i);
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j < i; j ++){
			if(a[j] < a[i]) b[i] ++;
		}
		for(int j = i + 1; j <= n; j ++){
			if(a[j] < a[i]) c[i] ++;
		}
	}
	int ans = 0;
	for(int id = mx; id >= 0; id --){
		int m = v[id].size();
		if(!m) continue;

	//	cout << id << endl;

		for(int i = 0; i <= m; i ++) for(int j = 0; j <= m; j ++) dp[i][j] = INF;
		for(int i = 1; i <= m; i ++) bb[i] = b[v[id][i-1]], cc[i] = c[v[id][i-1]];

	///	for(int i = 1; i <= m; i ++) printf("  %d %d\n", bb[i], cc[i]);
		dp[0][0] = 0;
		for(int i = 1; i <= m; i ++){
			for(int j = 0; j <= i; j ++){
				if(i > j){ dp[i][j] = min(dp[i][j], dp[i-1][j] + cc[i]); }
				if(j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + bb[i] + i - j);
			//	printf("%d ", dp[i][j]);
			}//puts("");
		}//puts("");
		int mn = INF;
		for(int i = 0; i <= m; i ++){
			mn = min(mn, dp[m][i]);
		} //puts("");
	///	cout <<"MN  " << mn << endl;
		ans += mn;
	}
	cout << ans << endl;
}