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
	int len, t;
	cin >> len >> t;
	string s;
	cin >> s;

	int dot = -1;
	vector<int> a;
	a.pb(0);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') dot = a.size(); else a.pb(s[i] - '0');
	}

	int cut = 1e9 + 1;
	for (int i = dot; i < a.size(); i++) if (a[i] >= 5) {
		t--;
		a[i] = 0;
		a[i - 1]++;
		cut = i - 1;
		for (int j = i - 1; j >= dot; j--) if (t > 0 && a[j] >= 5) {
			cut = j - 1;
			a[j] = 0;
			a[j - 1]++;
			t--;
		}
		break;
	}
	cut = min(cut, (int)a.size() - 1);
	for (int i = cut; i >= 1; i--) if (a[i] == 10) {
		a[i] = 0;
		a[i - 1]++;
	}
	int last = 0;
	for (int i = 0; i <= cut; i++) {
		if (a[i]) last = i;
	}		
	last = max(last, dot - 1);

	for (int i = 0; i <= last; i++) {
		if (i == dot) cout << '.';
		if (i == 0 && a[i] == 0) continue;
		cout << a[i];
	}
	cout << endl;


	return 0;
}