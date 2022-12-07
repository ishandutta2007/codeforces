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
string s[55];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ans = 0;

	for (int i = 0; i < n - 1; i++) for (int j = 0; j < m - 1; j++) {
		string t = "";
		t += s[i][j];
		t += s[i][j + 1];
		t += s[i + 1][j];
		t += s[i + 1][j + 1];
		string tt = "face";
		sort(t.begin(), t.end());
		sort(tt.begin(), tt.end());
		if (t == tt) ans++;
	}
	cout << ans << endl;
	return 0;
}