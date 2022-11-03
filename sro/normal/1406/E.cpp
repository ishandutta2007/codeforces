/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n;
int sus[1 << 17];
const int sq = 316;
vector<int> si;
int sum;

int Read() {
	int x; cin >> x;
	return x;
}

void trytofind() {
	cout << "A 1" << endl;
	if(Read() != sum) {
		loop(i, SZ(si)) {
			cout << "B " << si[i] << endl; Read();
			cout << "A " << si[i] << endl;
			if(Read()) {
				cout << "C " << si[i] << endl;
				exit(0);
			}
		}
	}
	si.clear();
}

int main() {
	cin >> n; sum = n;
	circ(i, 2, n) if(!sus[i]) {
		if(1ll * i * i > n) continue;
		range(j, i * i, n, i) sus[j] = 1;
	}
	circ(i, 2, min(n, sq)) {
		if(sus[i]) continue;
		cout << "B " << i << endl;
		sum -= Read();
	}
	cout << "A 1" << endl;
	if(Read() != sum) {
		int ub = n;
		int res = 1;
		circ(i, 2, ub) if(!sus[i]) {
			int mii = i;
			while(mii <= ub) {
				cout << "B " << res * i << endl;
				if(Read()) {
					res *= i;
					if(1ll * mii * i > ub) break;
					mii *= i;
				} else {
					break;
				}
			}
			ub = n / res;
		}
		cout << "C " << res << endl;
	} else {
		circ(i, sq + 1, n) {
			if(sus[i]) continue;
			cout << "B " << i << endl; sum--; Read();
			si.pub(i);
			if(SZ(si) == 100) {
				trytofind();
			}
		}
		if(SZ(si)) trytofind();
		cout << "C 1" << endl;
	}
	return 0;
}