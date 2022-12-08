#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 2000010

const ll mod = 1000000033;
const ll mult = 31;

string s, t;
ll pref[maxn];
ll thash;
ll pows[maxn];

ll gethash(int cstart, int cend) {
	ll cur = pref[cend];
	ll sub = cstart == 0 ? 0 : pref[cstart-1];

	sub = (sub * pows[cend-cstart+1])%mod;
	return (cur + mod - sub)%mod;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;

	int sl = s.length();
	int tl = t.length();

	if (sl > tl) {
		cout << 0 << endl;
		return 0;
	}

	// cout << "lenghts: " << sl << " " << tl << endl;

	int numz = 0;
	int numo = 0;


	if (s[0] == '1') {
		for (int i = 0; i < sl; i++) {
			if (s[i] == '0') s[i] = '1';
			else s[i] = '0';
		}
	}

	for (int i = 0; i < sl; i++) {
		if (s[i] == '0') numz++;
		else numo++;
	}

	pows[0] = 1LL;
	for (int i = 1; i <= 2*tl; i++) {
		pows[i] = (pows[i-1] * mult) %mod;
	}

	for (int i = 0; i < tl; i++) {
		if (i > 0) pref[i] = pref[i-1];

		pref[i] = (pref[i] * mult + t[i]-'a'+1) %mod;

		// cout << "dfklasdjf:   " << t[i]-'a' << endl;
	}

	thash = pref[tl-1];
	int ans = 0;

	for (int i = 1; i <= tl; i++) {
		int lenz = i;
		if (lenz * numz >= tl) break;
		int leno = (tl - lenz*numz)/numo;

		ll zhash = -1, ohash = -1;
		if (lenz*numz + leno*numo != tl || leno <= 0) continue;

		ll chash = 0;
		zhash = gethash(0, lenz-1);

		int curspot = 0;
		for (int j = 0; j < sl; j++) {
			if (s[j] == '0') {
				chash = (chash * pows[lenz] + zhash)%mod;

				curspot += lenz;
			}
			else {
				if (ohash == -1) {
					ohash = gethash(curspot, curspot + leno-1);
				}
				chash = (chash * pows[leno] + ohash)%mod;

				curspot += leno;
			}
		}

		// cout << "tried: " << zhash << " " << ohash << endl;
		// cout << "    " << lenz << " " << leno << endl;

		if (chash == thash && zhash != ohash && ohash != 0) ans++;
	}

	// cout << " thash: " << thash << endl;
	cout << ans << endl;





}