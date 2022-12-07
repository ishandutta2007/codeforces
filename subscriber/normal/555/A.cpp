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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int ma = 0;

	for (int i = 0; i < k; i++) {
		vector<int> a;
		int x;
		cin >> x;
		while (x--) {
			int t;
			cin >> t;
			a.pb(t);
		}

		int ic = 0;
		while (a.size() > ic && a[ic] == ic + 1) ic++;
		ma = max(ma, ic);
	}

	ma--;
	int ans = (n - k - ma) + (n - 1 - ma);
	cout << ans << endl;

	return 0;
}