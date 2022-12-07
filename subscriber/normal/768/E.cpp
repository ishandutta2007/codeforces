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

map<pair<int, long long >, int> was;

int gr(int x, long long w) {

	w &= pw(x + 1) - 1;
	if (was.find(mp(x, w)) != was.end()) return was[mp(x, w)];

	long long q = 0;

	for (int i = 1; i <= x; i++) if ((w & pw(i)) == 0) q |= pw(gr(x - i, w | pw(i)));

	int g = 0;
	while (q & pw(g)) g++;

//	cout << x << " " << w << " " << g << endl;

	return was[mp(x, w)] = g;
}
int ww[1000111];

int f(int x) {
	if (ww[x] != 0) return ww[x] - 1;

	ww[x] = gr(x, 0) + 1;
	return ww[x] - 1;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x;
		 cin >> x;
		 ans ^= f(x);
	}
	if (ans > 0) cout << "NO\n"; else cout << "YES\n";
	
	return 0;
}