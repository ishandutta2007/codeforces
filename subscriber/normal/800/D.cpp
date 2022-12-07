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

pair<int, pair<int, int> > dd[1000111];

int st[8];

pair<int, pair<int, int> > add(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	int s = (a.S.S * 1ll * b.S.S) % M;
	int s1 = (a.S.F * 1ll * b.S.S + b.S.F * 1ll * a.S.S) % M;

	int s2 = (a.F * 1ll * b.S.S + b.F * 1ll * a.S.S + (2ll * a.S.F * b.S.F) % M) % M;
	return mp(s2, mp(s1, s));
}

int was[1000111][7];

int go(int x, int o) {
	if (o == 6) return dd[x].F;

	if (was[x][o] != -1) return was[x][o];

	int ret = go(x, o + 1);

	int b = x / st[o] % 10;
	if (b < 9) ret = (ret - go(x + st[o], o + 1) + M) % M;

	return was[x][o] = ret;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i< 1000000; i++) dd[i] = mp(0, mp(0, 1));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		dd[a] = add(dd[a], mp(a * 1ll * a % M, mp(a, 2)));
	}

	st[0] = 1;
	for (int i = 1; i <= 6; i++) st[i] = st[i - 1] * 10;

	for (int i = 0; i < 6; i++) for (int j = 999999; j >= 0; j--) {
		int b = j / st[i] % 10;
		if (b > 0) dd[j - st[i]] = add(dd[j - st[i]], dd[j]);
	}

	for (int i = 0; i <= 1000000; i++) for (int j = 0; j < 7; j++) was[i][j] = -1;


	long long out = 0;
	for (int x = 0; x < 1000000; x++) {
		int val = go(x, 0);

		//if (val != 0) cerr << x << " " << val << endl;

		out ^= (x * 1ll * val);
	}
	cout << out << endl;



	return 0;
}