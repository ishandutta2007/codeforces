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
int lg[N];
int a[N];
int mi[20][N];
int ma[20][N];

int mic(int i, int j) {
	if (a[i] < a[j]) return i;
	return j;
}
int mac(int i, int j) {
	if (a[i] > a[j]) return i;
	return j;
}

int get_i(int l, int r) {	
	int w = lg[r - l + 1];
	return mic(mi[w][l], mi[w][r - pw(w) + 1]);
}
int get_a(int l, int r) {	
	int w = lg[r - l + 1];
	return mac(ma[w][l], ma[w][r - pw(w) + 1]);
}

int solve(int l, int r) {
	if (l == r) return 0;
	int x = get_i(l, r);
	int y = get_a(l, r);
	if (x == l && y == r) return 1;
	if (y == l && x == r) return 1;
	if (x == l || x == r) {
		return solve(l, y) + solve(y, r);
	} else {
		return solve(l, x) + solve(x, r);
	}
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
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		lg[1] = 0;
		for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
		for (int i = 0; i < n; i++) {
			mi[0][i] = ma[0][i] = i;
		}
		for (int i = 1; i <= lg[n]; i++) 
			for (int j = 0; j + pw(i) <= n; j++) {
				mi[i][j] = mic(mi[i - 1][j], mi[i - 1][j + pw(i - 1)]);
				ma[i][j] = mac(ma[i - 1][j], ma[i - 1][j + pw(i - 1)]);
			}
		cout << solve(0, n - 1) << endl;
	}		
	return 0;
}