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
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> q0, q1;

	for (int i = 1; i <= n; i++) if (i % 2) q0.pb(i); else q1.pb(i);

	int h0 = (a * b + 1) / 2;
	int h1 = (a * b) / 2;

	if (q1.size() > q0.size()) swap(q0, q1);

	if (q0.size() > h0 || q1.size() > h1) {
		puts("-1");
		return 0;
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			int t = 0;
			if ((i + j) % 2 == 0) {
				if (q0.size()) {
					t = q0.back();
					q0.pop_back();
				}
			} else {
				if (q1.size()) {
					t = q1.back();
					q1.pop_back();
				}
			}
			printf("%d", t);
			if (j + 1 == b) puts(""); else putchar(' ');
		}
	}

	return 0;
}