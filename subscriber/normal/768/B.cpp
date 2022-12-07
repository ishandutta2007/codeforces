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

long long x, l, r;

int get(long long x, long long k, long long all) {
	if (x <= 1) return x;

	long long left = all / 2;
	if (k <= left) return get(x / 2, k, all / 2);

	if (k == left + 1) return x % 2;

	return get(x / 2, k - (left + 1), all / 2);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> x >> l >> r;

	long long all = 0;
	long long mul = 1;

	long long y = x;
	for(;;) {
		all += mul;
		if (y <= 1) break;
		mul *= 2;
		y /= 2;
	}

	int ans = 0;
	for (long long i = l; i <= r; i++) ans += get(x, i, all);

	cout << ans << endl;

	return 0;
}