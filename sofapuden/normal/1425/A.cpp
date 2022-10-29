#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;cin >> t;
	while(t--){
		ll n; cin >> n;
		ll ans = 0;
		int cn = 0;
		while(n){
			if(!cn){
				if(n&1){
					ans++;
					n--;
				}
				else{
					if((n/2)&1 || n == 4){
						ans+=n/2;
						n/=2;
					}
					else{
						ans++;
						n--;
					}
				}
			}
			else{
				if(n&1){
					n--;
				}
				else{
					if((n/2)&1 || n == 4){
							n/=2;
					}
					else{
						n--;
					}
				}
			}
			cn ^=1;			
		}
		cout << ans << "\n";
	}
}