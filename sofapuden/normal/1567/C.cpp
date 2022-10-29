#include<bits/stdc++.h>

using namespace std;

const int MX = 3e5+5;

typedef long long ll;

ll dp[20][2][2];
string s;

ll fin(int x, bool nx, bool th){
	if(x >= s.size()){
		if(nx == 0 && th == 0)return 1;
		return 0;
	}
	if(dp[x][nx][th] != -1)return dp[x][nx][th];
	ll ans = 0;
	for(int i = 0; i <= 9; ++i){
		for(int j = 0; j <= 9; ++j){
			if((i+j+th)%10 == s[x]-'0'){
				ans+=fin(x+1,(i+j+th)>=10,nx);
			}
		}
	}
	return dp[x][nx][th] = ans;
}

int main(){
	int t; cin >> t;
	while(t--){
		for(int i = 0; i < 20; ++i)for(int j = 0; j < 2; ++j)for(int k = 0; k < 2; ++k)dp[i][j][k] = -1;
		cin >> s;
		reverse(s.begin(),s.end());
		cout << fin(0,0,0)-2 << '\n';
		
	}

}