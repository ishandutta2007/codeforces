#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
int n;

ll dist[maxn];
int tp[maxn];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dist[i];
		dist[i]*=2LL;
	}
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'G') tp[i] = 0;
		else if (s[i] == 'W') tp[i] = 1;
		else tp[i] = 2;
	}

	ll fw = 0LL; //fly when we could walk
	ll ww = 0LL; //walk when we could walk
	ll fs = 0LL; //fly when we could swim
	ll ss = 0LL; //swim when we could wim

	bool seenw = false; //have we seen water
	bool seeng = false; //have we seen grass
	ll ans = 0LL;

	ll stamina = 0LL;

	ll ns; //numswap
	for (int i = 1; i <= n; i++) {

		// cout << "on " << i << " : " << fs << " " << ans << endl;
		if (tp[i] == 1) seenw = true;
		if (tp[i] == 2) seeng = true;
		ll cd = dist[i];
		if (tp[i] == 2) {
			//build up stamina for this
			
			if (cd <= stamina) {
				stamina -= cd;
				ans += cd;
				continue;
			}
			cd -= stamina;
			ans += stamina;
			stamina = 0;

			if ( (cd+1)/2 <= fs) {
				ans +=  cd;
				ns = (cd+1)/2;

				ans -= ns;
				ans += 3*ns;
				fs -= ns;
				if (ns*2 != cd) stamina++;
				continue;
			}

			cd -= 2*fs;
			ans += 4*fs;
			fs = 0;


			// cout << cd << " left - " << ans << endl;

			if ( (cd+1)/2 <= fw) {
				ans += cd;
				ns = (cd+1)/2;

				ans -= ns;
				ans += 5*ns;

				fw -= ns;
				if (ns*2 != cd) stamina++;
				continue; 
			}

			cd -= 2*fw;
			ans += 6*fw;
			fw = 0;


			if (seenw) {
				ll bandf = (cd+1)/2;
				ans += 8*bandf;
				stamina = bandf*2 - cd;
			}
			else {
				ll bandf = (cd+1)/2;
				ans += 12*bandf;
				stamina = bandf*2 - cd;
			}
		}
		if (tp[i] == 1) {
			if (cd <= stamina) {
				stamina -= cd;
				fs += cd;
				ans += cd;
				continue;
			}
			cd -= stamina;
			fs += stamina;
			ans += stamina;
			stamina = 0;

			//now we have cd left to go and we have 0 stamina
			ll val = cd/2;
			ans += val*4;
			fs += val;
			ss += val;
			if (val*2 != cd) {
				ans += 3LL;
				stamina += 1LL;
				ss += 1LL;
			}
		}
		if (tp[i] == 0) {
			//walking is worse than swimming
			//swap with fly areas if we can
			if (cd <= stamina) {
				stamina -= cd;
				fw += cd;
				ans += cd;
				continue;
			}
			cd -= stamina;
			fs += stamina;
			ans += stamina;
			stamina = 0;

			//now we swap with fly when we could swim
			if ( (cd+1)/2 <= fs) {
				ans += cd;
				ns = (cd+1)/2;

				ans -= ns;
				ans += 3*ns;

				fs -= ns;
				fw += cd;

				if (ns * 2 != cd) stamina++;

				continue;
			}
			cd -= 2*fs;
			ans += 4*fs;

			ss += fs;
			fw += 2*fs;
			fs = 0;


			//now we have cd left to go and we have 0 stamina
			ll val = cd/2;
			ans += val*6LL;
			fw += val;
			ww += val;
			if (val*2 != cd) {
				ans += 5LL;
				stamina += 1LL;
				ww += 1LL;
			}


		}

	}

	cout << ans/2LL << endl;

	
}