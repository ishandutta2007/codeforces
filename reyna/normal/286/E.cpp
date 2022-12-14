//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int read() { int x; cin >> x; return x; }

typedef pair<double, double> point;

#define real first
#define imag second

inline point operator -(const point &a, const point &b) { return point(a.real - b.real, a.imag - b.imag); }
inline point operator +(const point &a, const point &b) { return point(a.real + b.real, a.imag + b.imag); }
inline point operator *(const point &a, const point &b) { return point(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real); }
const int N = 1 << 21, lg = 21;
int rev[N];
void FFT(point a[], bool inverse) {
	rep(i, N)
		if (rev[i] > i)
			swap(a[rev[i]], a[i]);
	double arg = acos(-1.0);
	for (int len = 2; len <= N; len <<= 1, arg /= 2) {
		point wn = point(cos(arg), inverse == 0? sin(arg): -sin(arg));
		for (int j = 0; j < N; j += len) {
			point w = point(1, 0);
			for (int x = j, y = j + len / 2; y < j + len; ++x, ++y) {
				point u = a[x], v = a[y] * w;
				a[x] = u + v;
				a[y] = u - v;
				w = w * wn;
			}
		}
	}
	if (inverse)
		rep(i, N)
			a[i].real /= N;
}


point a[N], b[N];
int mark[N], res[N], k, pt = 0;

void gen(int bit = lg - 1, int x = 0, int y = 0) {
	if (bit == -1) {
		rev[y] = x;
		return;
	}
	gen(bit - 1, x, y);
	gen(bit - 1, x + (1 << bit), y + (1 << lg - bit - 1));
}

int main() {
//	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
//	scanf("%d %d", &n, &m);
	scan(n);
	scan(m);
	rep(i, n) {
		int x; //scanf("%d", &x);
		scan(x);
		a[x].real = a[x].real + 1;
		mark[x]++;
	}
	gen();
	FFT(a, false);
	rep(i, N)
		b[i] = a[i] * a[i];
	FFT(b, true);
	rep(i, m + 1) {
		int x = (b[i].real > 0.5);
		int y = mark[i];
		if (x && !y) {
			puts("NO");
			return 0;
		} else if (y && x == 0) {
			res[k++] = i;
		}
	}
	puts("YES");
	
	printf("%d\n", k);
	rep(i, k)
		printf("%d ", res[i]);
//		cout << res[i] << ' ';
	
}