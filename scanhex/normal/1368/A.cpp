#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){ 
		nagai a,b,n ;
		cin >> a >> b >> n;
		int it=0;
		while(a <= n && b <= n) {
			++it;
			if(a < b)
				a += b;
			else
				b += a;
		}
		cout << it << '\n';
	}
	return 0;
}