#include<bits/stdc++.h>

using namespace std;

int dp[105][105][105][2];
const int INF = 1<<29;

vector<int> v;

int fin(int x, int od, int ev, bool ls){
	if(dp[x][od][ev][ls])return dp[x][od][ev][ls];
	if(x == v.size()){
		assert(od == 0 && ev == 0);
		return 0;
	}
	if(v[x] != 0){
		return dp[x][od][ev][ls] = fin(x+1,od,ev,v[x]&1)+((ls^v[x])&1);	
	}
	else{
		int ret = INF;
		if(od){
			ret = min(ret,fin(x+1,od-1,ev,1)+(ls^1));
		}
		if(ev){
			ret = min(ret,fin(x+1,od,ev-1,0)+ls);
		}
		return dp[x][od][ev][ls] = ret;
	}
}

int main(){
	int n; cin >> n;
	for(int i = 0; i < 105; ++i){
		for(int j = 0; j < 105; ++j){
			for(int k = 0; k < 105; ++k){
				dp[i][j][k][0] = 0;
				dp[i][j][k][1] = 0;
			}
		}
	}
	v.resize(n);
	for(auto &x : v)cin >> x;
	int od = (n+1)/2;
	int ev = n/2;
	for(int i = 0; i < n; ++i){
		if(v[i] == 0)continue;
		if(v[i]&1)od--;
		else ev--;
	}
	cout << min(fin(0,od,ev,0),fin(0,od,ev,1)) << '\n';
}