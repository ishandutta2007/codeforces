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

int n, k;
vector<int> v[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int u = 0;
	for (int i = k; i < n - 1; i++) {
		v[u].pb(i);
		u++;
		if (u == k) u = 0;
	}
	int ans = v[0].size() + v[1].size() + 2;
	cout << ans << endl;
	for (int i = 0; i < k; i++) {
		int last = i;
		for (int j = 0; j < v[i].size(); j++) {
			cout << last + 1 << " " << v[i][j] + 1 << endl;
			last = v[i][j];
		}
		cout << last + 1 << " " << n << endl;
	}
	return 0;
}