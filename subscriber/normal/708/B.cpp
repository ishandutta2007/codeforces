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

int h[N];
int a00, a01, a10, a11;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> a00 >> a01 >> a10 >> a11;
	if (a00 + (long long) a01 + a10 + a11 == 0) {
		cout << "1" << endl;
		return 0;
	}

	if (a01 + a10 == 0) {
		if (a00 > 0 && a11 > 0) {
			cout << "Impossible\n";
			return 0;
		}
	}

	int a = 0;
	int b = 0;
	if (a01 + a10 > 0) {
		a++;
		b++;
	}

	while (a * 1ll * (a - 1) / 2 < a00) a++;
	while (b * 1ll * (b - 1) / 2 < a11) b++;

	if (a * 1ll * (a - 1) / 2 != a00 || b * 1ll * (b - 1) / 2 != a11) {
		cout << "Impossible\n";
		return 0;
	}

	long long tot = a * 1ll * b;
	if (tot != a01 + a10) {
		cout << "Impossible\n";
		return 0;
	}
	
	for (int i = 0; i < b; i++) {
		int need = min(a, a10);
		h[need]++;
		a10 -= need;
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < h[a - i]; j++) cout << '1';
		cout << '0';
	}
	for (int j = 0; j < h[0]; j++) cout << '1';

	return 0;
}