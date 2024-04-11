#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	while(n--){
		string s; cin >> s;
		int x = s.size();
		map<char,int> M;
		for(char c : s)M[c]++;
		string an = "?";
		set<char> S;
		for(int i = 0; i < x; ++i){
			if(S.count(s[i])){
				M[s[i]]--;
				continue;
			}
			while(an.back() <= s[i]){
				if(M[an.back()] > 1){
					M[an.back()]--;
					S.erase(an.back());
					an.pop_back();
				}
				else{
					break;
				}
			}
			S.insert(s[i]);
			an+=s[i];
		}
		cout << an.substr(1) <<  "\n";

			
	}
}