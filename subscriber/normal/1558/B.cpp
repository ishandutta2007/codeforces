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

long long f[4000111];

long long ads[4000111];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	int n, m;
	cin >> n >> m;
	
	f[1] = 1;
	long long sum = 1;
	long long divs = 0;
	
	for (int i = 2; i <= n; i++) {
		f[i] = 0;
		
		divs = (divs + f[1]) % m; // div i
		
		divs = (divs + ads[i]) % m;
		
		f[i] = (sum + divs) % m;
		sum = (sum + f[i]) % m;
		for (int j = i + i; j <= n; j += i) ads[j] = (ads[j] - f[i - 1] + f[i] + m) % m;
	}
	cout << f[n] << endl;
	
	return 0;
}