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
#define N 411111

#define TASK "1"

using namespace std;

int n;
int a[N], b[N], used[N], u[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;

		u[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}
	int p = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (p < n && used[a[p]]) p++;
		if (a[p] == b[i]) {
		} else {
			ans++;
		}
		used[b[i]] = 1;
	}
	cout << ans << endl;
	return 0;
}