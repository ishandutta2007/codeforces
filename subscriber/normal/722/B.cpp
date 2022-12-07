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

int n;
int a[N];

string al = "aeiouy";

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) if (al.find(s[j]) < al.size()) cnt++;
		if (cnt != a[i]) {
			cout << "NO\n";
			return 0;
		} 
	}
	cout << "YES\n";

	return 0;
}