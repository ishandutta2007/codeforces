#include <bits/stdc++.h>

#define ll long long

using namespace std;
ll vals[11][11][61];

ll combos[61][61];

ll calc(int odd, int even, int leng) {
	if (leng < 0 || even < 0 || odd < 0) return 0;
	// cout << "calc:  " << odd << " " << even << " " << leng << endl;
	if (vals[odd][even][leng] != -1) {
		return vals[odd][even][leng];
	}
	ll cur = 0LL;
	if (odd > leng) {
		cur = 0;
	}
	else if (odd % 2 != leng %2) {
		cur = 0;
	}
	else if (leng == 0) {
		cur = 1;
	}
	else if (odd == 0 && even == 0) {
		cur = 0;
	}
	
	else if (odd > 0) {
		for (int i = 1; i <= leng; i+=2) {
			// cout << " " << leng << " " << i << " " << combos[leng][i] << endl;
			// cout << "-->  " << odd-1 << " " << even << " " << leng-i << 
			// 	" " << calc(odd-1, even, leng-i) << endl;
			cur += calc(odd-1,even,leng-i) * combos[leng][i];
			// cout << "cur:  " << cur << endl;
		}
	}
	else {
		for (int i = 0; i <= leng; i+=2) {
			cur += calc(odd, even-1, leng-i) * combos[leng][i];
		}
	}
	// cout << "cur:  " << cur << " " << odd << " " << even <<
	// 	" " << leng << endl;
	vals[odd][even][leng] = cur;
	return cur;
	
}

ll run(ll num, int base, bool low) {
	char buffer[62];
	_i64toa(num, buffer, base);
	string cur = buffer;
	ll ans = 0;
	// cout << cur << endl;
	for (int i = 1; i < cur.length(); i++) {
		// cout << "i:   " << i << " " << base << endl;
		// cout << "val  " << i-1 << "  " << calc(1, base-1, i-1) << endl;
		ans += (base-1)*calc(1, base-1, i-1);
		// cout << "a:  " << ans << endl;
	}
	// cout << "anshere:   " << cur << " " << ans << endl;
	int vals[base];
	for (int i = 0; i < base; i++) {
		vals[i] = 0;
	}
	for (int i = 0; i < cur.length(); i++) {
		
		for (int j = 0; j < cur[i]-'0'; j++) {
			if (i == 0 && j == 0) continue;
			int od = 0, ev = 0;
			for (int k = 0; k < base; k++) {
				if (k == j) continue;
				if (vals[k]%2==0) ev++;
				else od++;
			}
			if (vals[j]%2==1) ev++;
			else od++;
			// cout << od << " " << ev << " " << cur.length()-(i+2) << 
			// 	" " << calc(od, ev, cur.length()-(i+2)) << 
			// 	"   i:  " << i << endl;
			ans += calc(od, ev, cur.length()-(i+1));
		}
		vals[cur[i]-'0']++;
		
	}
	// vals[cur[cur.length()-1]-'0']++;
	bool ok = true;
	for (int i = 0; i < base; i++) {
		if (vals[i]%2==1) ok = false;
	}
	if (ok && !low) ans++;
	return ans;
}

int main() {
	//FAST IO FAST IO FAST IO FAST IO FAST IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	int b;
	ll l, r;
	for (int i = 0; i < 61; i++) {
		combos[i][0] = 1;
		combos[i][1] = i;
	}
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			for (int k = 0; k <= 60; k++) {
				vals[i][j][k] = -1;
			}
		}
	}
	for (int i = 1; i < 61; i++) {
		for (int j = 1; j <= i; j++) {
			combos[i][j] = combos[i-1][j-1] + combos[i-1][j];
		}
		for (int j = i+1; j < 61; j++) {
			combos[i][j] = 0;
		}
	}
	for (int numrun = 0; numrun < q; numrun++) {
		cin >> b >> l >> r;
		ll ans = run(r, b, false);
		// cout << "ans:  " << ans << endl;
		ans -= run(l, b, true);
		cout << ans << '\n';
	}
	// cin >> q;

}