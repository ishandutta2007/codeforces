#include<bits/stdc++.h>
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
#define N 411111
 
#define TASK "1"
 
using namespace std;
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long d9 = 1000*1000*1000;
		long long x = a + d9 * b;
		long long y = b;
		long long z = c;

/*		cout << x % y - a << endl;
		cout << y % z - b << endl;
		cout << z % x - c << endl;*/

		cout << x << " " << y << " " << z << endl;
	}		
	return 0;
}