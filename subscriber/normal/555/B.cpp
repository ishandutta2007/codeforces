#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
typedef pair<int,int> pt;

int n, m;
long long l[N], r[N], a[N];
int ans[N];

long long L[N], R[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	for (int i = 0; i < m; i++) cin >> a[i];

	vector<pair<long long, int> > ev;

	for (int i = 0; i < n - 1; i++) {
		L[i] = l[i + 1] - r[i];
		R[i] = r[i + 1] - l[i];
		
		ev.pb(mp(L[i], -(i + 1)));
		ev.pb(mp(R[i], i + 1000000));
	}
	for (int i = 0; i < m; i++) ev.pb(mp(a[i], i));
	sort(ev.begin(), ev.end());

	set<pair<long long, int> > Q;
	for (int i = 0; i < ev.size(); i++) {
		if (ev[i].S < 0) {
			int id = (-ev[i].S) - 1;
			Q.insert(mp(R[id], id));			
		} else if (ev[i].S >= 1000000) {
			int id = ev[i].S - 1000000;
			if (Q.find(mp(R[id], id)) != Q.end()) {
				puts("No");
				return 0;
			}
		} else {
			if (Q.size() > 0) {
				ans[(*Q.begin()).S] = ev[i].S + 1;
				Q.erase(Q.begin());
			}				
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n - 1; i++) {
		cout << ans[i];
		if (i + 1 < n - 1) cout << " "; else cout << endl;
	}

	return 0;
}