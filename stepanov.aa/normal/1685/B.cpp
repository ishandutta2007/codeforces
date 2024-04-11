#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <string>
#include <set>
#include <map>
#include <cassert>


using namespace std;


#define ll long long
#define ld long double
#define flt double
#define bp push_back
#define emb empalce_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define prcs cout << fixed << setprecision(10)
#define nlpt nullptr


mt19937_64 rnd(132123);

ll inf = 1e18;


int a, b, c, d;
int n;
string s;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		cin >> s;
		n = s.size();
		int ca = 0;
		int cb = 0;
		for (int i = 0; i < n; i += 1) {
			if (s[i] == 'A') {
				ca += 1;
			}
			else {
				cb += 1;
			}
		}
		if (a + c + d != ca || b + c + d != cb) {
			cout << "NO" << "\n";
			continue;
		}
		ll cnt0 = 0;
		vector<ll> cntc;
		vector<ll> cntd;
		ll smc = 0;
		ll smd = 0;
		int lst = 0;
		for (int i = 0; i < n; i += 1) {
			if (i == n - 1 || s[i] == s[i + 1]) {
				ll ln = i + 1 - lst;
				if (ln % 2 == 1) {
					cnt0 += ln / 2;
				}
				else {
					if (s[lst] == 'A') {
						cntc.push_back(ln / 2);
						smc += ln / 2;
					}
					else {
						cntd.push_back(ln / 2);
						smd += ln / 2;
					}
				}
				lst = i + 1;
			}
		}
		sort(rall(cntc));
		sort(rall(cntd));
		ll dc = 0;
		ll dd = 0;
		for (int i = 0; i < cntc.size() && smc - 1 > c; i += 1) {
			smc -= 1;
			cntc[i] -= 1;
			if (smc - c <= cntc[i]) {
				dc += smc - c;
				smc = c;
				continue;
			}
			else {
				dc += cntc[i];
				smc -= cntc[i];
			}
		}
		for (int i = 0; i < cntd.size() && smd - 1 > d; i += 1) {
			smd -= 1;
			cntd[i] -= 1;
			if (smd - d <= cntd[i]) {
				dd += smd - d;
				smd = d;
				continue;
			}
			else {
				dd += cntd[i];
				smd -= cntd[i];
			}
		}
		smc += dd;
		smd += dc;
		if (max(c - smc, 0ll) + max(d - smd, 0ll) > cnt0) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
	return 0;
}

/*
1
2 3 5 4
AABAABBABAAABABBABBBABB
*/