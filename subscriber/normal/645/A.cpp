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

vector<string> q[N];
int q1, q2;

set<vector<string> > was;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	vector<string> s;
	s.resize(2);

	cin >> s[0] >> s[1];

	vector<string> g;
	g.resize(2);

	cin >> g[0] >> g[1];

	was.insert(s);

	q[q1++] = s;

	while (q1 != q2) {
		vector<string> x = q[q2++];

		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
			for (int ii = 0; ii < 2; ii++) for (int jj = 0; jj < 2; jj++) if (x[i][j] == 'X' && abs(i - ii) + abs(j - jj) == 1) {
				vector<string> e = x;
				swap(e[i][j], e[ii][jj]);

				if (was.find(e) == was.end()) {
					was.insert(e);
					q[q1++] = e;
				}
			}
	}
	if (was.find(g) == was.end()) cout << "NO\n"; else cout << "YES\n";


	return 0;
}