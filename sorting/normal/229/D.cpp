#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5007;

int n, a[MAXN], prefix[MAXN];
array<int, 2> dp[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < i; ++j){
			int groups = dp[j][0] + 1, sum = prefix[i] - prefix[j];
			if(sum >= dp[j][1]){
				if(groups > dp[i][0]){
					dp[i] = {groups, sum};
				}
				else if(dp[i][0] == groups  && sum < dp[i][1]){
					dp[i][1] = sum;
				}
			}
		}
	}

	cout << n - dp[n][0] << "\n";

	return 0;
}