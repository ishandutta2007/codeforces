#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, c, r;
	cin >> a >> b >> c >> r;

	if(a > b)
		swap(a, b);

	int xa = c - r, xb = c + r;
	int ans = b - a;

	if(xa > b || a > xb){
		cout << ans << "\n";
	}
	else{
		if(xa < a && b < xb){
			cout << "0\n";
			return;
		}

		if(a <= xa && xb <= b){
			cout << ans - (xb - xa) << "\n";
		}
		else{
			if(a <= xb && xb <= b){
				cout << ans - (xb - a) << "\n";
			}
			else{
				cout << ans - (b - xa) << "\n";
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}