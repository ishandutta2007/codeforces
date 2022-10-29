#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		vector<int> o;
		int cn = 1;
		char hi = s[0];
		int ma = 1; 
		o.push_back(cn);
		for(int i = 1; i < n; ++i){
			if(s[i] == hi)cn++;
			if(!cn){
				hi = (hi == '1' ? '0' : '1');
				cn = ma+1;
			}
			ma = max(cn,ma);
			o.push_back(cn);
			if(s[i] != hi)cn--;
		}
		
		cout << ma << "\n";
		
		for(int i = 0; i < n; ++i){
			cout << o[i] << " ";
		}
		cout << "\n";			
	}		
}