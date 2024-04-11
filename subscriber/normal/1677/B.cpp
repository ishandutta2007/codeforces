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
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> col(m, 0);
		int good_col = 0;

		int first = -1;
		for (int i = 0; i < n * m; i++) if (s[i] == '1') {
			first = i;
			break;
		}

		int good_row = 0;
		vector<int> br(m, 0);

		int zero_streak = 0;

		for (int i = 0; i < n * m; i++) {
			if (s[i] == '1') {
				if (col[i % m] == 0) {
					col[i % m] = 1;
					good_col += 1;
				}
				zero_streak = 0;
			} else zero_streak++;
			if (first != -1 && i >= first) {
				if (zero_streak >= m) {
					br[i % m] += 1;
				}
				if ((i - first) % m == 0) good_row++;
			}	
			cout << good_col + good_row - br[i % m] << " ";
			
		}
		cout << endl;
	}		
	return 0;
}