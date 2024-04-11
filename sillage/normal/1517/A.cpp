#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		long long n;
		cin >> n;
		if (n % 2050 != 0) {
			puts("-1");
		}else{
			long long m = n / 2050;
			int ans = 0;
			while (m){
				ans += m % 10;
				m /= 10;
			}
			cout << ans << endl;
		}
	}
}