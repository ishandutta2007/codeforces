//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 505;
int need[Maxn][Maxn];
int dp[Maxn][Maxn];
int par[Maxn][Maxn];
string S;
void call(int st,int k){
	if(!st || !k){
		return;
	}
	call(par[st][k],k-1);
	if(k - 1)
		cout << '+';
	for(int i = par[st][k];i < st;i++){
		cout << min(S[i],S[st-1-(i-par[st][k])]);
	}
	return;
}
int main(){
	cin >> S;
	int k;
	cin >> k;
	int n = S.size();
	for(int i = 0; i < n;i++){
		for(int j = i;j < n;j++){
			for(int r = i; r <= j;r++){
				if(S[r] != S[j-(r-i)])
					need[i][j]++;
			}
			need[i][j] /= 2;
		}
	}
	for(int i = 0; i <= n;i++){
		for(int j = 0; j <= n;j++)
			dp[i][j] = Maxn;
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n;i++){
		for(int j = 0; j < i;j++){
			for(int r = 1; r <= k;r++){
				dp[i][r] = min(dp[i][r],dp[j][r-1] + need[j][i-1]);
				if(dp[i][r] == dp[j][r-1] + need[j][i-1])
					par[i][r] = j;
			}
		}
	}
	int best = Maxn;
	for(int i = 0; i <= k;i++){
		best = min(dp[n][i],best);
	}
	for(int i = 0; i <= k;i++){
		if(best == dp[n][i]){
			cout << best << endl;
			call(n,i);
			return 0;
		}
	}
	return 0;
}