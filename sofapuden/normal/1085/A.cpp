#include<bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	string s2;
	int n = s.size();
	for(int i = 0; i < n; ++i){
		if((i&1) == (n&1)){
			s2+=s[n-1-(i/2)];
		}
		else{
			s2+=s[i/2];
		}
	}
	reverse(s2.begin(),s2.end());
	cout << s2 << "\n";
}