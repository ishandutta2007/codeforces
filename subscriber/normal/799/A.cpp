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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);


	int n, t, k, d;
	cin >> n >> t >> k >> d;

	int cur = (n + k - 1) / k * t;

	int tt = cur - 1;

	int cnt = tt / t * k;
	if (tt >= d) cnt += (tt - d) / t * k;

	if (cnt >= n) cout << "YES" << endl; else cout << "NO" << endl;


	return 0;
}