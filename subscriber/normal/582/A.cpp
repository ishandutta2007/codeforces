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

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	set<pair<int, int> > S;
	set<pair<int, int> >::iterator it;
	for (int i = 0; i < n * n; i++) {
		int x;
		scanf("%d", &x);
		S.insert(mp(-x, i));
	}
	vector<int > ans;
	for (int i = 0; i < n; i++) {
		it = S.begin();
		int x = -(*it).F;

		ans.pb(x);

		for (int j = 0; j < ans.size(); j++) for (int t = 0; t < 2; t++) {
			if (j + 1 == ans.size() && t == 1) continue;
			int g = __gcd(ans[j], x);

			it = S.lower_bound(mp(-g, 0));
//			cout << "del " << (*it).F << endl;
			S.erase(it);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i + 1 == n) puts(""); else putchar(' ');
	}
	return 0;
}