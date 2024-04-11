#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define maxl 100000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	int n;
	cin >> q;
	ll k;
	string pref = "What are you doing while sending \"";
	// cout << pref << endl;
	string mid = "\"? Are you busy? Will you send \"";
	string suc = "\"?";
	string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
	// cout << pref << endl;
	// cout << mid << endl;
	// cout << suc << endl;
	// cout << pref.length() << " " << mid.length() << " " << suc.length() << endl;
	int pl = pref.length();
	int ml = mid.length();
	int sl = suc.length();
	ll lens[maxl+1];
	lens[0] = f0.length();
	ll maxcur = 2000000000000000000LL;
	// cout << maxcur << endl;
	for (int i = 1; i <= maxl; i++) {
		lens[i] = pl + lens[i-1] + ml + lens[i-1] + sl;
		lens[i] = min(lens[i], maxcur);
	}	
	// strign mid = 
	for (int t = 0; t < q; t++) {
		cin >> n >> k;
		while (n >= 0) {
			if (n == 0) {
				if (f0.length() >= k) {
					cout << f0[k-1];
					break;
				}
				else {
					cout << ".";
					break;
				}
			}
			// cout << " --->  n  " << n << endl;
			if (lens[n] < k) {
				cout << ".";
				break;
			}
			if (pl >= k) {
				cout << pref[k-1];
				break;
			}
			k -= pl;
			if (n > 0 && lens[n-1] >= k) {
				n--;
				continue;
			}
			k -= lens[n-1];
			if (ml >= k) {
				cout << mid[k-1];
				break;
			}
			k -= ml;
			if (lens[n-1] >= k) {
				n--;
				continue;
			}
			k -= lens[n-1];
			if (sl >= k) {
				cout << suc[k-1];
				break;
			}
		}

	}
	cout << endl;
	// cin >> n;

}