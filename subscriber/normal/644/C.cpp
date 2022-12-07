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

map<string, vector<string> > ma;

map<vector<string>, vector<string> > ma2;


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int u = s.size();
		for (int i = 7; i < s.size(); i++) if (s[i] == '/') {
			u = i;
			break;
		}
		string na = s.substr(0, u);
		string t = s.substr(u);

		ma[na].pb(t);
//		cout << na << " " << t << endl;
	}

	for (auto it = ma.begin(); it != ma.end(); it++) {
		vector<string> t = it -> S;
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());

		ma2[t].pb(it -> F);
	}
	vector<vector<string> > ans;
	for (auto it = ma2.begin(); it != ma2.end(); it++) if ((it -> S).size() > 1) {
		ans.pb(it -> S);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
		cout << endl;
	}		

	return 0;
}