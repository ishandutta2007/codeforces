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
#define N 411111

#define TASK "1"

using namespace std;

int have1[5000444], have2[5000444];
int a[2000222];
int n;

vector<int> o;

void find(int x) {
    o.pb(x);
    if (have1[x]) return;
    have1[x] = 1;
    for (int i = 0; i<= 21; i++) if (x & pw(i)) find(x ^ pw(i));
}

void find2(int x) {
    if (have2[x]) return;
    if (have1[x] != 2) return;
    have2[x] = true;
    for (int i = 0; i <= 21; i++) if (x & pw(i)) find2(x - pw(i));
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
	    int x = a[i];
	    int y = 0;
	    for (int j = 21; j >= 0; j--) if ((x & pw(j)) == 0) {
	        if (have2[y + pw(j)]) {
	            y += pw(j);
	        }
	    }
	    if (have2[y]) ans = max(ans, x + y);
	    
	    o.clear();
	    find(x);
	    for (int z : o) {
	        find2(z);
	    }
	    for (int z : o) have1[z] = 2;
	}
	cout << ans << endl;

	return 0;
}