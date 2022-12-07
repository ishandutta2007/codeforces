#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int n;
int a[222][5];

int su[5];

int get(int a, int b) {

	if (a * 2 > b) return 500;
	if (a * 4 > b) return 1000;
	if (a * 8 > b) return 1500;
	if (a * 16 > b) return 2000;
	if (a * 32 > b) return 2500;
	return 3000;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) {
		cin >> a[i][j];
		if (a[i][j] != -1) su[j]++;
	}

	for (int mid = 0; mid <= 1000000; mid++) {

		int bal = 0;

		for (int i = 0; i < 5; i++) {
			int att = n;
			int solv = su[i];

			att += mid;
			if (a[0][i] != -1 && (a[1][i] != -1 && a[0][i] > a[1][i]) ) {
				solv += mid;
			}
			int cost = get(solv, att);

			if (a[0][i] != -1) {
				bal += cost - (cost / 250 * a[0][i]);
			}
			if (a[1][i] != -1) {
				bal -= cost - (cost / 250 * a[1][i]);
			}
		}
		if (bal > 0) {
			cout << mid << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}