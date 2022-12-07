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
 
int main(){
	#ifdef home
//		freopen(TASK".in","r",stdin);	
//		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		string s = "";
		for (int j =  0; j < m; j++) s.push_back('0');
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> a[i];
	}
	vector<pair<int, int> > e;
	for (int i = 0; i < m; i++) e.push_back(mp(a[i], i));
	sort(e.begin(), e.end());
	string s = "";	
	for (int j =  0; j < m; j++) s.push_back('0');
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		s[e[i].S] = '1';
		cout << "? " << s << endl;
		long long x;
		cin >> x;
		if (ans + e[i].F == x) ans = x; else s[e[i].S] = '0';
	}
	cout << "! " << ans << endl;
	return 0;
}