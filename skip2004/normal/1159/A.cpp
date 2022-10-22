#include<bits/stdc++.h>
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::string str; std::cin >> str >> str;
	int cnt = 0,mx = 0,mn = 0;
	for(char i : str){
		if(i == '+') ++ cnt;
		if(i == '-') -- cnt;
		mn = std::min(cnt,mn);
	}
	std::cout << cnt - mn << '\n';
}