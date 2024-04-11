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

string s;
map<pair<int, int>, int> was;

int isu(int l, int r) {
	if (r == s.size()) return 1;
	if (was.find(mp(l, r)) != was.end()) return was[mp(l, r)];

	int ret = 0;
	for (int i = 2; i <= 3; i++) {
		if (r + i > s.size()) break;
		if (s.substr(l, r - l) == s.substr(r, i)) continue;

		ret |= isu(r, r + i);	
	}
	return was[mp(l, r)] = ret;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> s;

	set<string> ans;

	for (int i = 5; i < s.size(); i++) for (int j = 2; j <= 3; j++) if (i + j <= s.size()) if (isu(i, i + j)) ans.insert(s.substr(i, j ));
	cout << ans.size() << endl;

	for (auto it = ans.begin(); it != ans.end(); it++) cout << (*it) << endl;

	return 0;
}