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

int a, b, c, l;

long long bad(int a, int b, int c) {
	long long ret = 0;
	for (int i = 0; i <= l; i++) {
		int aa = a + i;

		int r = l - i;

		int s = b + c;
		if (s > aa) continue;

		r = min(r, aa - s);

		long long k = (1 + (r + 1)) * 1ll * (r + 1) / 2;
		ret += k;
	}
	return ret;

}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> a >> b >> c >> l;

	long long all = 0;
	for (int i = 0; i <= l; i++) {
		int r = l - i;

		long long k = (1 + (r + 1))  * 1ll * (r + 1) / 2;
		all += k;
	}
//	cout << all << endl;

	all -= bad(a, b, c);
	all -= bad(b, a, c);
	all -= bad(c, a, b);

	cout << all << endl;

	return 0;
}