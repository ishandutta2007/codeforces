#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s1, s2; cin >> s1 >> s2;
		int a = 0, b = 0;
		for(int i = 0; i < n; ++i){
			if(s1[i] == s2[i])continue;
			if(s1[i] > s2[i])a++;
			else b++;
		}
		if(a == b)cout << "EQUAL\n";
		if(a > b)cout << "RED\n";
		if(a < b)cout << "BLUE\n";
	}
}