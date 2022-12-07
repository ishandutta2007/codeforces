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
#define N 211111

#define TASK "1"

using namespace std;

int n;
int a[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	n++;
	for (int i = 0; i < n; i++) cin >> a[i];
	int id = -1;
	for (int i = 0; i < n - 1; i++) if (a[i] > 1 && a[i + 1] > 1) {
		id = i;
		break;
	}
	if (id == -1) {
		cout << "perfect" << endl;
		return 0;
	}
	vector<int> e1, e2;
	int last = 0;
	for (int i = 0; i < n; i++) {
					
		for (int j = 0; j < a[i]; j++) {
			e1.pb(last);	
			if (i == id + 1) {
				if (j == 0) {
					e2.pb(last - 1);
				} else e2.pb(last);
			} else {
				e2.pb(last);	
			}
		}
		last = e1.size();
	}
	cout << "ambiguous" << endl;
	for (int i = 0; i < e1.size(); i++) cout << e1[i] << " ";
	cout << endl;
	for (int i = 0; i < e1.size(); i++) cout << e2[i] << " ";
	cout << endl;
	return 0;
}