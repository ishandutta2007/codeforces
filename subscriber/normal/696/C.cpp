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

int pv(int a, long long b, int mod) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2, mod);
	r = r * r % mod;
	if (b % 2) r = r * a % mod;
	return r;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);  
	int k;
	cin >> k;
	vector<long long> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];

	int p = 1;
	for (int i = 0; i < k; i++) p = p * 1ll * (a[i] % (M - 1)) % (M - 1);


	int den = pv(2, p, M);
	den = den * 1ll * pv(2, M - 2, M) % M;

	int num = den;
	int ch = 1;
	for (int i = 0; i < k; i++) if (a[i] % 2 == 0) ch = -1;
//	ch *= -1;
	num = (num - ch + M) % M;

	num = num * 1ll * pv(3, M - 2, M) % M;


	cout << num << "/" << den << endl;

	return 0;
}