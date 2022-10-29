#include <bits/stdc++.h>

using namespace std;

int main(){
	int j; cin >> j;
	while(j--){
		string s; cin >> s;
		bool ok = 0;
		int n = s.size();
		string t;
		for(int i = 0; i < n; ++i){
			if(!ok && s[n-i-1] != 'a'){t+='a';ok = 1;};
			t+=s[i];
		}
		if(t.size() == s.size())cout << "NO\n";
		else cout << "YES\n" << t << "\n";
	}
}