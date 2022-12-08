#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int onexor = 0;
	bool ok = true;
	ll s, x;
	cin >> s >> x;
	for (int i = 40; i >= 0; i--) {
		if (s & (1LL << i)) {
			if (x & (1LL << i)) {
				continue; //this is fine
			}
			else  {
				//now we keep trying to flow over a one
				bool foun = false;
				for (int j = i-1; j >= 0; j--) {
					if (!(x & (1LL << j))) { //we can overlap here
						foun = true;
						i = j+1;
						break;
					}
					if (s & (1LL << (j))) {
						ok = false;
						break;
					}
					
				}
				if (!foun) {
					ok = false;
					break;
				}
	

			}
		}
		else if (x & (1LL << i)) {
			ok = false;
		}
	}
	ll ans = 1LL;
	for (int i = 40; i >= 0; i--) {
		if (x & (1LL << i)) {
			ans = ans*2LL;
		}
	}
	if (x == s) ans -= 2LL;
	if (ok) {
		cout << ans << endl;
	}
	else cout <<0 << endl;
	cin >> s;

}