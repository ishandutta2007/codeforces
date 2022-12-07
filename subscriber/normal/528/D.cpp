#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<complex>
#include<cstring>
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
#define M 1000000007

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

typedef complex<double> base;
const double PI = acos(-1);
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

string D = "AGCT";
const int N = (1<< 19);

int bad[666000];
int n, m, k;

char s1[666000], s2[666000];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d%d\n", &n, &m, &k);
	gets(s1);
	gets(s2);

	vector<base> a(N), b(N);

	for (int u = 0; u < 4; u++) {
		vector<int> ps;
		for (int i = 0; i < n; i++) if (s1[i] == D[u]) ps.pb(i);

		for (int i = 0; i < N; i++) a[i] = base(0, 0);

		if (ps.size() == 0) {
			for (int i = 0; i < n; i++) a[i] = base(1, 0);
		} else {
			for (int i = 1; i < ps.size(); i++) {
				int l = ps[i - 1] + (k + 1);
				int r = ps[i] - (k + 1);
				if (l <= r) {
					for (int j = l; j <= r; j++) a[n - 1 - j] = base(1, 0); 
				}
			}
			if (ps[0] - k - 1 >= 0) 
				for (int j = 0; j <= ps[0] - k - 1; j++) a[n - 1 - j] = base(1, 0);
			if (ps.back() + k + 1 < n)
				for (int j = ps.back() + k + 1; j < n; j++) a[n - 1 - j] = base(1, 0);				
		}

		for (int j = 0; j < N; j++) b[j] = base(0, 0);
		for (int j = 0; j < m; j++) if (s2[j] == D[u]) b[j] = base(1, 0);

		fft(a, 0);
		fft(b, 0);
		for (int i = 0; i < N; i++) a[i] *= b[i];
		fft(a, 1);
		for (int i = 0; i < n; i++) if (a[i].real() > 0.5) bad[i] = 1;	
	}
	int ans = 0;	
	for (int i = 0; i + m <= n; i++) if (bad[n - 1 - i] == 0) ans++;
	cout << ans << endl;


	return 0;
}