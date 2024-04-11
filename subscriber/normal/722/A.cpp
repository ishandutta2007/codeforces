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
	int type;
	string s;
	cin >> type >> s;

	int ans = 0;

	if (s[3] > '5') s[3] = '0';

	int h = s[0] - '0';
	h *= 10;
	h += s[1] - '0';

	if (type == 24) {
		if (h > 23) s[0] = '0';
	} else {
		if (h > 12) {
			if (h % 10 == 0) {
				s[0] = '1';
			} else {
				s[0] = '0';
			}				
		} else if (h == 0) {
			s[1] = '1';
		}
	}
	cout << s << endl;


	return 0;
}