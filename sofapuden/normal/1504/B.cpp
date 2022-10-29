#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s1, s2; cin >> s1 >> s2;
		int cn = 0;
		for(int i = 0; i < n; ++i){
			cn+=(s1[i] == '0'?1:-1);
		}
		bool swp = 0;
		bool ok = 1;
		for(int i = n-1; i >= 0; --i){
			if(swp)s1[i] = (s1[i] == '1' ? '0' : '1');
			if(!cn){
				if(s1[i] != s2[i])swp^=1;
				s1[i] = s2[i];
			}
			cn-=(s1[i] == '0'?1:-1);
			if(s1[i] != s2[i])ok = 0;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}