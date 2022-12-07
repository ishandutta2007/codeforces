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
string s[111];
int a[111][111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int t = 1;
		if (s[i][j] == 'B') t = -1;

		a[i + 1][j + 1] += t;
		a[i][j + 1] -= t;
		a[i + 1][j] -= t;
		a[i][j] += t;
	}	
/*	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
		cout << endl;
	}		*/
	int ans = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] != 0) ans++;
	cout << ans << endl;
	return 0;
}