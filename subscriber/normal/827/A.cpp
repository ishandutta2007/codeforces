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
#define N 2011111

#define TASK "1"

using namespace std;

int n;
int k[N];
vector<int> v[100111];
string s[100111];
int p[N];
char ans[N];

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	vector<pair<int, int> > q;
	cin >> n;
	int len = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		cin >> k[i];
		v[i].resize(k[i]);
		for (int j = 0; j < k[i]; j++) {
			cin >> v[i][j];
			v[i][j]--;
			len = max(len, v[i][j] + (int)s[i].size());
		}
		q.pb(mp(s[i].size(), i));
	}
	for (int i = 0; i < len + 1; i++) p[i] = i;
	sort(q.rbegin(), q.rend());
	for (int i = 0; i < q.size(); i++) {
		int id = q[i].S;
		for (int j = 0; j < k[id]; j++) {
			int st = get(v[id][j]);

			int ll = st - v[id][j];


			for (int l = ll; l < s[id].size(); l++) {
				int pos = v[id][j] + l;
				if (ans[pos] == 0) {
					ans[pos] = s[id][l];
					p[pos] = p[pos + 1];
				} else break;
			}
		}
	}
	for (int i = 0; i < len; i++) if (ans[i] == 0) ans[i] = 'a';
	for (int i = 0; i < len; i++) cout << ans[i];
	cout << endl;

	return 0;
}