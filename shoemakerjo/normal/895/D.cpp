#include <bits/stdc++.h>

using namespace std;
#define maxn 1000010
#define ll long long

ll mod;

ll fact[maxn];
ll invfact[maxn];
ll inv[maxn];

ll powe(ll base, int p) {
	if (p == 0) return 1ll;
	if (p == 1) return base;
	if (p %2 == 1) {
		ll tempo = powe(base, p-1);
		ll cur = (tempo*base)%mod;
		return cur;
	}
	ll tempo = powe(base, p/2);
	ll cur = (tempo*tempo)%mod;
	return cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int n = a.length();
	int let[26];
	int leto[26];
	for (int i = 0; i < 26; i++) {
		let[i] = leto[i] =  0;
	}
	mod = 1000000007LL;
	for (int i = 0; i < n; i++) {
		let[a[i]-'a']++;
		leto[a[i]-'a']++;
	}
	fact[0] = 1LL;
	invfact[0] = 1LL;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i-1]*(i+0LL))%mod;
		invfact[i] = powe(fact[i], mod-2);
		inv[i] = powe(i, mod-2);
	}

	ll ans = 0LL;
	ll curp = fact[n];
	for (int i = 0; i < 26; i++) {
		curp = (curp*invfact[let[i]])%mod;
	}
	for (int i = 0; i < n; i++) {
		// cout << "curp  " << i << " " << curp << endl;
		int cur = b[i]-'a';
		for (int j = 0; j < cur; j++) {
			if (let[j] == 0) continue;
			ll tempo = (curp*let[j])%mod;
			tempo = (tempo*inv[n-i])%mod;
			ans = (ans+tempo)%mod;
			// cout << "j  " << j << " " << tempo << endl;
		}
		// cout << "i  " << i << "  " << ans << endl;
		if (let[cur] == 0) break;
		curp = (curp*let[cur])%mod;
		curp = (curp*inv[n-i])%mod;
		let[cur]--;

	}
	ll sub = 0LL;
	curp = fact[n];
	for (int i = 0; i < 26; i++) {
		let[i] = leto[i];
	}
	for (int i = 0; i < 26; i++) {
		curp = (curp*invfact[let[i]])%mod;
	}
	for (int i = 0; i < n; i++) {
		// cout << "curp  " << i << " " << curp << endl;
		int cur = a[i]-'a';
		for (int j = 0; j < cur; j++) {
			if (let[j] == 0) continue;
			ll tempo = (curp*let[j])%mod;
			tempo = (tempo*inv[n-i])%mod;
			sub = (sub+tempo)%mod;
			// cout << "j  " << j << " " << tempo << endl;
		}
		// cout << "i  " << i << "  " << ans << endl;
		if (let[cur] == 0) break;
		curp = (curp*let[cur])%mod;
		curp = (curp*inv[n-i])%mod;
		let[cur]--;

	}
	ans = (ans+mod-sub)%mod;

	if (ans == 0LL) ans = mod;
	ans = ans-1LL;
	cout << ans << endl;
	cin >> ans;

}