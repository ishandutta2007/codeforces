#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, c, d;
		string s; cin >> a >> b >> c >> d >> s;
		int e = 0, f = 0;
		for(char x : s){if(x == '0')e++;else f++;}
		int ans = b*e+c*f;
		ans = min(a*b+f*d,ans);
		ans = min(a*c+e*d,ans);
		cout << ans << "\n";
	}
}