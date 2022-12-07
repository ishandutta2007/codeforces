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

int st = 0;

string nn() {
	string t = "";
	st++;
	t.pb(('A') + st / 26);
	t.pb(('a') + st % 26);
	return t;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<string> e;

	for (int i = 0; i < k - 1; i++) e.pb(nn());
	for (int i = k - 1; i < n; i++) {
		string x;
		cin >> x;
		if (x == "YES") e.pb(nn()); else e.pb(e[e.size() - k + 1]);
	}
	for (int i = 0; i < n; i++) cout << e[i] << " ";

	return 0;
}