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
int n, a[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	int mi = 1e9 + 1;
	int ma = -1e9 - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) if (mi < a[i] && a[i] < ma) ans++;
	cout << ans << endl;

	return 0;
}