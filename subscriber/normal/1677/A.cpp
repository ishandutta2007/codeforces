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

int ps[5055][5055];
int p[5055];

long long solve() {
	int n;
	cin >> n;
	for (int i = 0;  i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int c = 2; c < n; c++) {
		ps[c][0] = 0;
		for (int i = 0; i < c; i++) ps[c][i + 1] = ps[c][i] + (p[i] < p[c]);
	}
	long long ans = 0;
	for (int b = 1; b < n; b++) {
		int x = 0;
		for (int c = n - 1; c > b; c--) {
		        ans += ps[c][b] * 1ll * x;
			x += (p[c] < p[b]);
		}
	}
	return ans;
}
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
		cout << solve() << endl;
	}	
	return 0;
}