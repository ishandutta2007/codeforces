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
#define N 411111
 
#define TASK "1"
 
using namespace std;

int n;
const int M = (1 << 21);
int have[M];
int l[M];
int r[M];


long long ok(long long x) {
	long long h = sqrt(x);
	if ((h + 1) * (h + 1) <= x) h++;
	long long u = (h + 1) * (h + 1) - x;
	if (x - (h * h) < u) return 0;
	return u;
}
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		have[x] = 1;
	}		
	int sz = M;
	for (int i = 0; i < M; i++) {
		if (have[i]) l[i] = r[i] = i; else l[i] = r[i] = -1;
	}
	int nq = 2;
	for (long long k = 0; ;) {
		long long good = 0;

		int g = sqrt(sz);
		for (int i = 0; i < sz; i++) {
			if (l[i] == -1) continue;
			good = max(good, ok(l[i] + k));
			good = max(good, ok(r[i] + k));
			if (good > 0 && i > g) break;
		}
		if (good == 0) {
			cout << k << endl;
			break;
                }

		while (k >= (1 << nq) * 1ll * (1 << nq) ) {
			nq++;
			int sz2 = 0;
			for (int i = 0; i < sz; i += 2) {

				if (l[i] == -1) {
					l[sz2] = l[i + 1];
					r[sz2] = r[i + 1];
				} else if (l[i + 1] == -1) {
					l[sz2] = l[i];
					r[sz2] = r[i];
				} else {
					l[sz2] = l[i];
					r[sz2] = r[i + 1];
				}
				sz2++;
			}
			sz = sz2;
		}
		k += good;
	}

	return 0;
}