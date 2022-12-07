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
string s[111];
int c[111], h[111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++) c[i] = 0;

	for (int i = 0; i < n; i++) cin >> h[i];
	

	vector<int> ans;
	for(;;) {
		int ok = 1;
		for (int i = 0; i < n; i++) if (c[i] == h[i]) {
			ok = 0;
			for (int j = 0; j < n; j++) if (s[i][j] == '1') c[j]++;
			ans.pb(i);
		}
		if (ok) break;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1;
		if (i + 1 == ans.size()) puts(""); else cout << " ";
	}
	
	return 0;
}