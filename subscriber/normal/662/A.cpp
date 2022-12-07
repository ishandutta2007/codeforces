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
#define N 511111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
long long a[N], b[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	long long tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		tot ^= a[i];
		b[i] ^= a[i];
	}
	int bs = 0;	
	
	for (int i = 0; i < 62; i++) {
		int x = -1;
		for (int j = bs; j < n; j++) if (b[j] & pw(i)) {
			x = j;
			break;
		}
		if (x == -1) continue;
		swap(b[bs], b[x]);

		for (int j = 0; j < n; j++) if (j != bs && b[j] & pw(i)) {
			b[j] ^= b[bs];
		}
		bs++;
	}
	for (int i = 0; i < 62; i++) if (tot & pw(i)) {
		int x = -1;
		for (int j = 0; j < bs; j++) if (b[j] & pw(i)) x = j;
		if (x == -1) {
			cout << "1/1" <<endl;
			return 0;
		}
		tot ^= b[x];
	}
	if (tot != 0) {
		cout << "1/1" << endl;
		return 0;
	}
	cout << pw(bs) - 1 << "/" << pw(bs) << endl;


	return 0;
}