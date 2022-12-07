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

long long was[N][2];
int a[N];
int n;

long long f(int x, int o) {
	if (was[x][o]) return was[x][o] - 1;
	long long ret = 0;

	if (x + 1 < n) {
		long long val = f(x + 1, o ^ 1);
		if (o == 0) val += abs(a[x + 1] - a[x]); else val -= abs(a[x + 1] - a[x]);
		ret= max(ret, val);
	}
	was[x][o] = ret + 1;
	return ret;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	long long ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, f(i, 0));
	cout << ans << endl;
	return 0;
}