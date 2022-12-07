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
#define M 1000000007
#define N 1505

#define TASK "1"

using namespace std;

map<int, int > was;

int f(int x) {
    if (was.count(x)) return was[x];
    set<int> t;
    for (int i = 1; i < x; i++) t.insert(f(i) ^ f(x - i));
    for (int i = 0; ; i++) if (t.find(i) == t.end()) return was[x] = i;

}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
	        int n;
	        cin >> n;
	       int a[n];
	       int x = 0;
	       for (int i = 0; i < n; i++) {
	            cin >> a[i];
	            x ^= f(a[i]);
	       }
	       if (x) cout << "errorgorn" <<endl; else cout << "maomao90" << endl;
	}
	return 0;
}