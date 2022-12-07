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
int c[N], d[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i] >> d[i];

	int all1 = 1;

	for (int i = 0; i < n; i++) if (d[i] == 2) all1 = 0;

	if (all1) {
		cout << "Infinity" << endl;
		return 0;		
	}

	int found = 0;

	int ps =  -1;


	for (int i = 0; i < n - 1; i++) if (d[i] != d[i + 1]) {
		found = 1;

		ps = 1900;

		for (int j = 0; j <= i; j++) ps -= c[j];
		break;
	}

	if (!found) {
		int ma = -1e9;
		int id = -1;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			cur += c[i];
			if (cur > ma) {
				ma = cur;
				id = i;
			}			
		}
		ps = 1900;
		for (int i = 0; i <= id; i++) ps -= c[i];
	}
	for (int s = ps + 250; s >= ps - 250; s--) {
		int h = s;
		int bad = 0;
		for (int i = 0; i < n; i++) {
			if (h >= 1900 && d[i] == 2 || h < 1900 && d[i] == 1) {
				bad = 1;
				break;
			}
			h += c[i];
		}
		if (!bad) {
			cout << h << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;


	return 0;
}