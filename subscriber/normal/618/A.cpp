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
	int n;
	cin >> n;
	vector<int> e;

	for (int i = 0; i < n; i++) {
		e.pb(1);

		while (e.size() > 1 && e.back() == e[e.size() - 2]) {
			int x = e.back() + 1;
			e.pop_back();
			e.pop_back();
			e.pb(x);
		}
	}
	for (int i = 0; i < e.size(); i++) {
		cout << e[i];
		if (i + 1 < e.size()) cout << " "; else cout << endl;
	}
	return 0;
}