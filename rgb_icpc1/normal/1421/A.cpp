#include <bits/stdc++.h>
using namespace std;

#define Bit(x) (1LL << x)
typedef long long LL;

int main() {
//	freopen("in.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Tc; cin >> Tc;
	while(Tc --) {
		long long a, b; cin >> a >> b;
		long long ans = 0; 
		for(int i = 0; i <= 32; i ++) {
			LL u = Bit(i) & a;
			LL v = Bit(i) & b;
			if(u != v) ans += Bit(i);
		}
		cout << ans << endl;
	}
	
	return 0;
}