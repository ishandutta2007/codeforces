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

int n, k;
int a[1000111];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	long long sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

	sort(a, a + n);

	int moves = k;

	int amin, amax;
	
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && a[i] == a[j]) j++;

		int st = a[i];

		int g = 1e9 + 5;
		if (j < n) g = a[j] - a[i];

		if (g * 1ll * j <= moves) {
			moves -= g * 1ll * j;
		} else {
			amin = st + moves / j;
			break;
		}

		i = j;
	}
	if (amin > sum / n) amin = sum / n;

	moves = k;
	reverse(a, a + n);

	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && a[i] == a[j]) j++;

		int st = a[i];

		int g = 1e9 + 5;
		if (j < n) g = a[i] - a[j];

		if (g * 1ll * j <= moves) {
			moves -= g * 1ll * j;
		} else {
			amax = st - moves / j;
			break;
		}
		i = j;
	}

	if (amax < (sum + n - 1) / n) amax = (sum + n - 1) / n;

	cout << amax - amin << endl;
	

	return 0;
}