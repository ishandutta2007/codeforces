#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		int n = a.size(), m = b.size();
		int cn1 = 0, cn2 = 0;
		if((n&1) != (m&1))cn1++;
		while(cn1 < n){
			if(cn2 >= m)break;
			if(a[cn1] == b[cn2]){
				cn1++, cn2++;
			}
			else{
				cn1+=2;
			}
		}
		if(cn2 >= m){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}