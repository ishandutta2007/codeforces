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

int n;
int a[55][55], ans[55];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	for (int k = 1; k <= n; k++) {
		for (int t = 0; t < n; t++) if (ans[t] == 0) {
			int ok = 1;

			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i == t || j == t) {
				if (i == j) continue;
				if (a[i][j] < k) continue;
				if (a[i][j] > k) ok = 0;
			}
			if (ok) {
				ans[t] = k;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i + 1 < n) cout << " "; else cout << endl;
	}
	return 0;
}