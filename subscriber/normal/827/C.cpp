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

int fe[4][10][100111];

map<char, int> wh;

string s, ss;
int n;

int type[N], x[N], l[N], r[N];
char c[N];
string e[N];
int ans[N];

void add(int A, int B, int x, int v) {
	while (x < s.size()) {
		fe[A][B][x] += v;
		x |= x + 1;
	}
}

int get(int A, int B, int x) {
	int r = 0;
	while (x >= 0) {
		r += fe[A][B][x];
		x = (x & (x + 1)) - 1;
	}
	return r;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	wh['A'] = 0;
	wh['T'] = 1;
	wh['G'] = 2;
	wh['C'] = 3;
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> type[i];
		if (type[i] == 1) {
			cin >> x[i] >> c[i];
			x[i]--;
		} else {
			cin >> l[i] >> r[i] >> e[i];
			l[i]--;
			r[i]--;
		}
	}
	for (int h = 1; h <= 10; h++) {
		for (int i = 0; i < 4; i++) for (int j = 0; j < h; j++) for (int k = 0; k < s.size(); k++) fe[i][j][k] = 0;
		for (int i = 0; i < s.size(); i++) {
			add(wh[s[i]], i % h, i, 1);
		}
		ss = s;
		for (int i = 0; i < n; i++) {	
			if (type[i] == 1) {
				add(wh[ss[x[i]]], x[i] % h, x[i], -1);
				ss[x[i]] = c[i];
				add(wh[ss[x[i]]], x[i] % h, x[i], 1);
			} else if (e[i].size() == h) {
				ans[i] = 0;
				for (int j = 0; j < e[i].size(); j++) {
					ans[i] += get(wh[e[i][j]], (l[i] + j) % h, r[i]);
					ans[i] -= get(wh[e[i][j]], (l[i] + j) % h, l[i] - 1);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) if (type[i] == 2) cout << ans[i] << endl;

	return 0;
}