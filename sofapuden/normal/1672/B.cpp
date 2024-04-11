#include<bits/stdc++.h>

using namespace std;

void solve(int testID){
	string s; cin >> s;
	int a = 0, b = 0;
	for(auto x : s){
		if(x == 'A')a++;
		else b++;
		if(b > a)break;
	}
	cout << (b <= a  && s.back() == 'B'? "YES" : "NO") << '\n';
}

int main(){
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}