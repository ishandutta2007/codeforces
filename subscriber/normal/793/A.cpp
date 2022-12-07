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

int a[N];
int n, k;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += (int)1e9;
	}
	for (int i = 1; i < n; i++) if (a[i] % k != a[i - 1] % k) {
		cout << -1 << endl;
		return 0;
	}
	int mi = 0;
	for (int i = 1; i < n; i++) if (a[i] / k < a[mi] / k) mi = i;

	long long sum = 0;
	for (int i = 0; i < n; i++) sum += (a[i] / k - a[mi] / k);
	cout << sum << endl;
	return 0;
}