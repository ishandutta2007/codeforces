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


set<string> w;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	while (n--) {
		string t;
		cin >> t;
		string a = t.substr(0, 3);
		string b = t.substr(5, 3);

		if (a == s) a = b;

		if (w.find(a) != w.end()) w.erase(a); else w.insert(a);
	}
	if (w.size() > 0) cout << "contest\n"; else cout << "home\n";
	return 0;
}