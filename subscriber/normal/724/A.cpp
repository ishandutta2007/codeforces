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

int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(string s) {
	if (s[0] == 'm') return 0;
	if (s[0] == 'w') return 2;
	if (s[0] == 'f') return 4;
	if (s[0] == 's' && s[1] == 'a') return 5;
	if (s[0] == 's' && s[1] == 'u') return 6;
	if (s[1] == 'u') return 1;
	if (s[1] == 'h') return 3;
	assert(0);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;

	int x1 = get(s1);
	int x2 = get(s2);

	for (int s = 0; s < 7; s++) {
		int cur = s;
		for (int i = 0; i < 11; i++) {
			int nex = (cur + d[i]) % 7;
			if (cur == x1 && nex == x2) {
				cout << "YES\n";
				return 0;
			}
			cur = nex;
		}
	}
	cout << "NO\n";

	return 0;
}