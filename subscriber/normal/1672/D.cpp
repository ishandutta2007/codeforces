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

string solve() {
		int n;
		cin >> n;
		int a[n];
		int b[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		map<int, int> can_del;
		map<int, int> have;

		for (int i = 0; i < n; i++) have[a[i]]++;

		int pa = n - 1;
		have[a[pa]]--;
		for (int i = n - 1; i >= 0; i--) {
			if (b[i] != a[pa]) return "NO";
			if (i == 0) break;

			if (pa == 0) return "NO";

			if (b[i - 1] == a[pa - 1]) {
				have[a[pa - 1]]--;
				pa--;
				continue;
			}
			int need = b[i - 1];
			if (have[need] > 0 && b[i] == b[i - 1]) {
				can_del[need] += 1;
				have[need] -= 1;
				continue;	
			}
			while (pa > 0 && a[pa - 1] != need && can_del[a[pa - 1]] > 0) {
				can_del[a[pa - 1]] -= 1;
				pa--;
			}
			if (pa > 0 && a[pa - 1] == need) {
				have[a[pa - 1]]--;
				pa--;
				continue;
			} else return "NO";
		}
		return "YES";
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
		cout << solve() << endl;
	}	
	return 0;
}