//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 620;
bool dp[Maxn][Maxn];
pair<pair<int,int>,int> par[Maxn][Maxn];
int L[Maxn],R[Maxn];
int ans[Maxn*2];
void call(pair<pair<int,int>,int> now,int f){
	int l = now.first.first;
	int r = now.first.second;
	if(l >= 2 * Maxn)
		l-=2*Maxn;
	if(l == r){
		ans[f] = 1;
		return;
	}
	if(par[l][r].first.first >= 2 * Maxn){
		int j = par[l][r].first.first-2*Maxn;
		call(make_pair(make_pair(l,j),j),f);
		call(make_pair(make_pair(j+1,r),j),f+(j-l+1)*2);
	}else{
		ans[f] = 1;
		call(make_pair(make_pair(l+1,r),r),f+1);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++)
		cin >> L[i] >> R[i];
	for(int i = 0; i < n;i++){
		if(L[i] == 1){
			dp[i][i] = 1;
			par[i][i] = make_pair(make_pair(-1,-1),-1);
		}
	}
	if(L[n-1] != 1){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(int i = n-2; i >= 0;i--){
		for(int j = max((L[i]/2)*2+1,3);j < R[i]+1;j++){
			if(dp[i+1][i+((j-1)/2)]){
				dp[i][i+((j-1)/2)] = 1;
				par[i][i+((j-1)/2)] = make_pair(make_pair(i+1,(i+((j-1)/2))),j+1);
			}
		}
		for(int j = i;j < n;j++){
			if(dp[i][j])
				for(int k = j+1; k < n;k++){
					if(dp[j+1][k]){
						dp[i][k] = 1;
						par[i][k] = make_pair(make_pair(2 * Maxn + j,k-1),k);
					}
				}
		}
	}
	if(!dp[0][n-1]){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	ans[0] = 1;
	call(make_pair(make_pair(0,n-1),2 * n),0);
	for(int i = 0; i < 2 * n;i++){
		if(ans[i])
			cout << '(';
		else
			cout << ')';
	}
	cout << endl;
	return 0;
}