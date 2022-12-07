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
#define next ggfgf

#define TASK "1"

using namespace std;

int n, start, X;

long long rd() {
	long long r = 0;
	for (int i = 0; i < 60; i++) if (rand() % 2) r += pw(i);
	return r;
}

int val[N];
int next[N];


int main(){
	#ifdef home
//		freopen(TASK".in","r",stdin);	
//		freopen(TASK".out","w",stdout);
	#endif		
	srand((int)time(0));
	ios::sync_with_stdio(false);
	cin >> n >> start >> X;

	int t = 1000;

	int best = start - 1;

	cout << "? " << best + 1 << endl;
	cin >> val[best] >> next[best];
	next[best]--;


	for (int i = 0; i < t; i++) {
		int x = rd() % n;
		cout << "? " << x + 1 << endl;

		cin >> val[x] >> next[x];
		next[x]--;

		if (val[x] <= X) {
			if (val[x] > val[best]) best = x;
		}
	}
//	cerr << "# " << best << endl;
	while (val[best] < X) {
		if (next[best] < 0) {
			cout << "! " << -1 << endl;
			break;
		}
		best = next[best];
		cout << "? " << best + 1 << endl;

		cin >> val[best] >> next[best];
		next[best]--;
	}
	cout << "! " << val[best] << endl;
	return 0;
}