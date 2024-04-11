//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 5e2 + 20;
long long dp[Maxn * 2][Maxn * 2];
long long C[Maxn * 2][Maxn * 2];
int col[Maxn];
int n,m,Mod;
long long rec(int i,int j){
//	cerr << i << " " << j << endl;
	if(i < 0 || j < 0)
		return -1;
	if(dp[i][j] != -1)
		return dp[i][j];
	long long ret = 0;
	ret += (rec(i - 2,j) * C[i][2])%Mod;
	ret %= Mod;
	if(i)
		ret += (rec(i,j - 1) * i * j)%Mod;
	ret %= Mod;
	ret += (rec(i + 2,j - 2) * C[j][2])%Mod;
	ret %= Mod;
	return dp[i][j] = ret % Mod;
}
int main(){
	cin >> n >> m >> Mod;
	for(int i = 0; i < m;i++){
		string S;
		cin >> S;
		for(int j = 0;j < n;j++)
			col[j] += S[j] - '0';
	}
	for(int i = 0; i <= n * 2;i++)
		for(int j = 0; j <= n * 2;j++)
			dp[i][j] = -1;
	for(int i = 0; i <= n * 2;i++){
		for(int j = 0; j <= i;j++){
			if(i == j || j == 0)
				C[i][j] = 1;
			else
				C[i][j] = (C[i-1][j] + C[i-1][j-1])%Mod;
		}
	}
	dp[0][0] = 1;
	int one = 0;
	int two = 0;
	for(int i = 0; i < n;i++){
		if(col[i] == 1)
			one++;
		if(col[i] == 0)
			two++;
	}
	if(one + two * 2 != (n - m) * 2){
		cout << 0 << endl;
		return 0;
	}
	cout << rec(one,two) % Mod << endl;
	return 0;
}