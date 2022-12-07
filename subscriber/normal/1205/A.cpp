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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >>  n;
	int a[n * 2];
	int cur = 1;

	if (n % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a[i] = cur;
			a[(i + n) % (n + n)] = cur + 1;
		} else {
			a[i] = cur + 1;
			a[(i + n) % (n + n)] = cur;
		}
		cur += 2;		
	}
	if (0) for (int i = 0; i < n * 2; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) sum += (a[(i + j) % (n + n)]);
		cout << sum << endl;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n * 2; i++) cout << a[i] << " ";
	return 0;
}