#include <bits/stdc++.h>

using namespace std;

const int N = 2007;
const int inf = 1e9 + 7;

int a[N];
int dp[N][N];

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, p;

	cin >> s >> p;

	for(int i = 0; i < s.size(); i++){
		int j = i, k = 0;

		while(j < s.size() && k < p.size()){
			if(s[j] == p[k]){
				j++;
				k++;

				continue;
			}

			j++;
		}

		if(k == p.size()){
			a[i] = j - i;
		}else{
			a[i] = inf;
		}

		//cout << a[i] << " - " << i << endl;
	}

	dp[s.size()][0] = 0;
	for(int i = 1; i <= s.size(); i++){
		dp[s.size()][i] = -inf;
	}

	for(int i = s.size() - 1; i >= 0; i--){
		for(int j = 0; j <= s.size(); j++){
			dp[i][j] = dp[i+1][j];
			if(j >= 1){
				dp[i][j] = max(dp[i+1][j-1], dp[i][j]);
			}
			if(j >= a[i] - p.size()){
				dp[i][j] = max(dp[i][j], dp[i + a[i]][j - (a[i] - p.size())] + 1);
			}

			//cout << dp[i][j] << " = " << i << " " << j << endl;
		}
	}

	for(int i = 0; i <= s.size(); i++){
		cout << dp[0][i] << " ";
	}
	cout << "\n";

	return 0;
}