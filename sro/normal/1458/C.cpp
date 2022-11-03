/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
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

//  W * H  dat
template<typename dat, int W, int H = W> struct Matrix {
	dat t[W][H];
	Matrix(dat x = 0) {loop(i, W) loop(j, H) t[i][j] = (i == j ? x : dat(0));}
	dat inline *operator[](int l) {return t[l];}
	dat inline const *operator[](int l) const {return t[l];}
	friend inline Matrix &operator+=(Matrix &a, const Matrix &b) {loop(i, W) loop(j, H) a[i][j] += b[i][j];}
	friend inline Matrix operator+(Matrix a, const Matrix &b) {return a += b;}
	friend inline Matrix &operator-=(Matrix &a, const Matrix &b) {loop(i, W) loop(j, H) a[i][j] -= b[i][j];}
	friend inline Matrix operator-(Matrix a, const Matrix &b) {return a -= b;}
	template<int T> friend inline Matrix<dat, W, T> operator*(const Matrix<dat, W, H> &a, const Matrix<dat, H, T> &b) {
		static Matrix<dat, W, T> res; res = Matrix<dat, W, T>(0);
		loop(i, W) loop(j, H) if(a[i][j]) loop(k, T) if(b[j][k]) res[i][k] += a[i][j] * b[j][k];
		return res;
	}
	friend inline Matrix &operator*=(Matrix &a, const Matrix<dat, H> &b) {return a = a * b;}
	void debug(int w = W, int h = H) {loop(i, w) {loop(j, h) cerr << t[i][j] << ' ';; cerr << endl;} cerr << endl;}
};

int jt = 998244353;
struct ModInt {
	int x;
	ModInt(int v = 0) {x = v; if(x >= jt || x < 0) {x %= jt; if(x < 0) x += jt;}}
	ModInt(ll v) {x = v % jt; if(x < 0) x += jt;}
	operator int() const {return x;}
	friend inline ModInt &operator+=(ModInt &a, const ModInt &b) {a.x += b.x; if(a.x >= jt) a.x -= jt; return a;}
	friend inline ModInt operator+(ModInt a, const ModInt &b) {return a += b;}
	friend inline ModInt operator+(ModInt a, int b) {return a += ModInt(b);}
	friend inline ModInt operator+(int a, ModInt b) {return b += ModInt(a);}
	friend inline ModInt &operator++(ModInt &a) {return a += 1;}
	friend inline ModInt &operator-=(ModInt &a, const ModInt &b) {a.x -= b.x; if(a.x < 0) a.x += jt; return a;}
	friend inline ModInt operator-(ModInt a, const ModInt &b) {return a -= b;}
	friend inline ModInt operator-(ModInt a, int b) {return a -= ModInt(b);}
	friend inline ModInt operator-(int a, ModInt b) {return ModInt(a) - b;}
	friend inline ModInt &operator--(ModInt &a) {return a -= 1;}
	friend inline ModInt &operator*=(ModInt &a, const ModInt &b) {a.x = (ll)a.x * b.x % jt; return a;}
	friend inline ModInt operator*(ModInt a, const ModInt &b) {return a *= b;}
	friend inline ModInt operator*(ModInt a, int b) {return a *= ModInt(b);}
	friend inline ModInt operator*(int a, ModInt b) {return b *= ModInt(a);}
	static inline void exgcd(ll a, ll b, ll &x, ll &y) {b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);}
	friend inline ModInt inv(const ModInt &a) {ll x, y; exgcd(a, jt, x, y); return x;}
	friend inline ModInt operator/(const ModInt &a, const ModInt &b) {return a * inv(b);}
	friend inline ModInt operator/(ModInt a, int b) {return a * inv(ModInt(b));}
	friend inline ModInt operator/(int a, ModInt b) {return ModInt(a) * inv(b);}
	friend inline ModInt operator/=(ModInt &a, const ModInt &b) {return a = a / b;}
};
typedef ModInt mint;

int n, m;
int a[1005][1005], b[1005][1005];
Matrix<mint, 4> mat;
char s[1 << 17];

void solve() {
	scanf("%d%d", &n, &m); jt = n;
	cont(i, n) cont(j, n) scanf("%d", a[i] + j);
	mat = Matrix<mint, 4>(1);
	scanf("%s", s + 1);
	cont(i, m) {
		Matrix<mint, 4> tr(1);
		if(s[i] == 'L') tr[1][3] = -1;
		else if(s[i] == 'R') tr[1][3] = 1;
		else if(s[i] == 'U') tr[0][3] = -1;
		else if(s[i] == 'D') tr[0][3] = 1;
		else if(s[i] == 'I') swap(tr[1][1], tr[1][2]), swap(tr[2][1], tr[2][2]);
		else if(s[i] == 'C') swap(tr[0][0], tr[0][2]), swap(tr[2][0], tr[2][2]);
		mat = tr * mat;
	}
	cont(i, n) cont(j, n) {
		Matrix<mint, 4, 1> mm;
		mm[0][0] = i - 1; mm[1][0] = j - 1; mm[2][0] = a[i][j] - 1; mm[3][0] = 1;
		mm = mat * mm;
		b[int(mm[0][0]) + 1][int(mm[1][0]) + 1] = int(mm[2][0]) + 1;
	}
	cont(i, n) cont(j, n) printf("%d%c", b[i][j], " \n"[j == n]);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}