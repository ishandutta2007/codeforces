#include<iostream>
#include<string>

typedef long long ll;

using namespace std;

int main(){
	string s;
	cin>>s;
	ll dp[100][100] , counter = 0 , x = 0 , ans = 0;
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			dp[i][j] = i * j;
		}
	}
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'Q'){
			counter++;
		}
	}
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'Q'){
			x++;
		} else if(s[i] == 'A'){
			ans += dp[counter - x][x];
		}
	}
	cout<<ans<<endl;
	return 0;
}