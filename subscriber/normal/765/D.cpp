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
int f[N], h[N], g[N], me[N];
int in[N], out[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		f[i]--;

		if (f[i] != i) {
			in[f[i]] = 1;
			out[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) if (in[i] && out[i]) {
		cout << -1 <<endl;
		return 0;
	}
	vector<int> np;
	for (int i = 0; i < n; i++) if (f[i] == i) {
		np.pb(i);
		h[np.size() - 1] = i;

		me[i] = np.size() - 1;
	}
	for (int i = 0; i < n; i++) g[i] = me[f[i]];

	cout << np.size() << endl;
	for (int i = 0; i < n; i++) {
		cout << g[i] + 1;
		if (i + 1 < n) cout << " "; else cout << endl;
	}
	for (int i = 0; i < np.size(); i++) {
		cout << h[i] + 1;
		if (i + 1 < np.size()) cout << " "; else cout << endl;
	}
	return 0;
}