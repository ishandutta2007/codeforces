#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	char getc () {return gc();}
	inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
	template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print; using io :: getc;
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 55, M = 20100;
int s[N][M];
int f[N][M], pmx[N][M], smx[N][M];
int n, m, k;

int Sum(int i, int l, int r){
	if(l > m || r < 1 || l > r) return 0;
	if(r > m) r = m;
	if(l < 1) l = 1;
	return s[i][r] - s[i][l-1];
}

int q[M], l, r;

int main(){
	// File("f2");
	gi(n); gi(m); gi(k);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			gi(s[i][j]);
			s[i][j] += s[i][j-1];
		}
	for(int i=1; i<=m; i++) f[1][i] = Sum(1, i, i+k-1), pmx[1][i] = max(pmx[1][i-1], f[1][i] + Sum(2, i, i+k-1));
	for(int i=m; i>=1; i--) smx[1][i] = max(smx[1][i+1], f[1][i] + Sum(2, i, i+k-1));
	for(int i=2; i<=n; i++){
		l = 1; r = 0;
		for(int j=1; j<=m; j++){
			while(l <= r && j - q[l] >= k) ++l;
			while(l <= r && f[i-1][j] >= f[i-1][q[r]] + Sum(i, q[r], j - 1)) --r;
			q[++r] = j;
			f[i][j] = f[i-1][q[l]] + Sum(i, q[l], j + k - 1);
			if(j - k >= 1) upmax(f[i][j], pmx[i-1][j-k] + Sum(i, j, j+k-1));
			if(j + k <= m) upmax(f[i][j], smx[i-1][j+k] + Sum(i, j, j+k-1));
		}
		l = 1; r = 0;
		for(int j=m; j>=1; j--){
			while(l <= r && q[l] - j >= k) ++l;
			while(l <= r && f[i-1][j] >= f[i-1][q[r]] + Sum(i, j + k, q[r] + k - 1)) --r;
			q[++r] = j;
			upmax(f[i][j] ,f[i-1][q[l]] + Sum(i, j, q[l] + k - 1));
			smx[i][j] = max(smx[i][j+1], f[i][j] + Sum(i+1, j, j+k-1));
		}
		for(int j=1; j<=m; j++) pmx[i][j] = max(pmx[i][j-1], f[i][j] + Sum(i+1, j, j+k-1));
	}
	printf("%d\n", pmx[n][m]);
	return 0;
}