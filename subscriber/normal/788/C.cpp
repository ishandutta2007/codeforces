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

int d[2222], have[2222];
int q[2222], q1, q2;
int n , k;


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		have[x] = 1;
	}
	for (int i = 0; i <= 2000; i++) d[i] = 1e9 + 1;
	
	for (int i = 0; i <= 1000; i++) if (have[i]) {
		int to = n - i + 1000;
		if (d[to] != 1) {
			d[to] = 1;
			q[q1++] = to;
		}
	}
	while (q1 != q2) {
		int x= q[q2++];
		for (int i = 0; i <= 1000; i++) if (have[i]) {
			int to = x + n - i;
			if (to >= 0 && to <= 2000 && d[to] > 1e9) {
				d[to] = d[x] + 1;
				q[q1++] = to;
			}
		}
	}
	if (d[1000] > 1e9) d[1000] = -1;
	cout << d[1000] << endl;


	return 0;
}