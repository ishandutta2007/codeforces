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

int cnt[1024], cnt2[1024];

int n, k, x;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		int qq;
		cin >> qq;
		cnt[qq]++;
	}

	while (k--) {
		memset(cnt2, 0, sizeof(cnt2));
		int t = 0;

		for (int i = 0; i < 1024; i++) {
			int a = (cnt[i] >> 1);
			a += (cnt[i] & 1) & (t ^ 1);

			t ^= (cnt[i] & 1);

			cnt2[i ^ x] += a; 
			cnt2[i] += (cnt[i] - a);
		}
		for (int i = 0; i < 1024; i++) cnt[i] = cnt2[i];
	}
	int mi = -1, ma= -1;
	for (int i = 0; i < 1024; i++) if (cnt[i] > 0) {
		if (mi == -1) mi = i;
		ma = i;
	}
	cout << ma <<  " " << mi << endl;


	return 0;
}