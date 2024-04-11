//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,avx,avx2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define hash hash228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

namespace fast {
	/** Fast input-output */
	 
	template <class T = int> inline T readInt();						
	inline double readDouble();
	inline int readUInt();					 
	inline int readChar(); // first non-blank character
	inline void readWord(char *s); 
	inline bool readLine(char *s); // do not save '\n'
	inline bool isEof();
	inline int getChar(); 
	inline int peekChar();
	inline bool seekEof();
	inline void skipBlanks();
	 
	template <class T> inline void writeInt(T x, char end = 0, int len = -1);
	inline void writeChar(int x); 
	inline void writeWord(const char *s);
	inline void writeDouble(double x, int len = 0);
	inline void flush();
	 
	static struct buffer_flusher_t {
		~buffer_flusher_t() {
			flush();
		}
	} buffer_flusher;
	 
	/** Read */
	 
	static const int buf_size = 4096;
	 
	static unsigned char buf[buf_size];
	static int buf_len = 0, buf_pos = 0;
	 
	inline bool isEof() {
		if (buf_pos == buf_len) {
			buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
			if (buf_pos == buf_len)
				return 1;
		}
		return 0;
	}
	 
	inline int getChar() { 
		return isEof() ? -1 : buf[buf_pos++];
	}
	 
	inline int peekChar() { 
		return isEof() ? -1 : buf[buf_pos];
	}
	 
	inline bool seekEof() { 
		int c;
		while ((c = peekChar()) != -1 && c <= 32)
			buf_pos++;
		return c == -1;
	}
	 
	inline void skipBlanks() {
		while (!isEof() && buf[buf_pos] <= 32U)
			buf_pos++;
	}
	 
	inline int readChar() {
		int c = getChar();
		while (c != -1 && c <= 32)
			c = getChar();
		return c;
	}
	 
	inline int readUInt() {
		int c = readChar(), x = 0;
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		return x;
	}
	 
	template <class T>
	inline T readInt() {
		int s = 1, c = readChar();
		T x = 0;
		if (c == '-')
			s = -1, c = getChar();
		else if (c == '+')
			c = getChar();
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		return s == 1 ? x : -x;
	}
	 
	inline double readDouble() {
		int s = 1, c = readChar();
		double x = 0;
		if (c == '-')
			s = -1, c = getChar();
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		if (c == '.') {
			c = getChar();
			double coef = 1;
			while ('0' <= c && c <= '9')
				x += (c - '0') * (coef *= 1e-1), c = getChar();
		}
		return s == 1 ? x : -x;
	}
	 
	inline void readWord(string & s) { 
		int c = readChar();
		while (c > 32)
			s += c, c = getChar();
		//*s = 0;
	}
	 
	inline bool readLine(char *s) { 
		int c = getChar();
		while (c != '\n' && c != -1)
			*s++ = c, c = getChar();
		*s = 0;
		return c != -1;
	}
	 
	/** Write */
	 
	static int write_buf_pos = 0;
	static char write_buf[buf_size];
	 
	inline void writeChar(int x) {
		if (write_buf_pos == buf_size)
			fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
		write_buf[write_buf_pos++] = x;
	}
	 
	inline void flush() {
		if (write_buf_pos) {
			fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
			fflush(stdout);
		}
	}
	 
	template <class T> 
	inline void writeInt(T x, char end, int output_len) {
		if (x < 0)
			writeChar('-'), x = -x;
	 
		char s[24];
		int n = 0;
		while (x || !n)
			s[n++] = '0' + x % 10, x /= 10;
		while (n < output_len)
			s[n++] = '0';
		while (n--)
			writeChar(s[n]);
		if (end)
			writeChar(end);
	}
	 
	inline void writeWord(const char *s) {
		while (*s)
			writeChar(*s++);
	}
	 
	inline void writeDouble(double x, int output_len) {
		if (x < 0)
			writeChar('-'), x = -x;
		int t = (int)x;
		writeInt(t), x -= t;
		writeChar('.');
		for (int i = output_len - 1; i > 0; i--) {
			x *= 10;
			t = std::min(9, (int)x);
			writeChar('0' + t), x -= t;
		}
		x *= 10;
		t = std::min(9, (int)(x + 0.5));
		writeChar('0' + t);
	}
}

using namespace fast;


mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7;
const int base = rnd() % 1000 + 228 + 1337;
const int MAXLEN = 1000001;
const int MAXN = 100000;

int n;
string a[MAXN];
int order[2][MAXLEN], dp[2][MAXLEN], nxtDiff[MAXLEN], hash[2][MAXLEN], pows[MAXLEN];
int ans;

inline int add(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

inline int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

inline int mul(int a, int b) {
	return (ll) a * b % MOD;
}

inline void prebuild() {
	pows[0] = 1;
	for (int i = 1; i < MAXLEN; ++i) {
		pows[i] = mul(pows[i - 1], base);
	}
}

inline void init(string & s) {
	hash[1][0] = 0;
	for (int i = 1; i <= (int)s.size(); ++i) {
		hash[1][i] = add(mul(hash[1][i - 1], base), s[i - 1]);
	}
}

inline int get(int ind, int l, int r) {
	if (r < l) return 0;
	return sub(hash[ind][r], mul(hash[ind][l - 1], pows[r - l + 1]));
}

inline int getHash(int ind, int r, int ban) {
	ban++;
	if (ban > r) return hash[ind][r];
	r++;
	return add(mul(hash[ind][ban - 1], pows[r - ban]), get(ind, ban + 1, r));
}

inline void read() {
	//cin >> n;
	n = readInt();
	for (int i = 0; i < n; ++i) {
		//cin >> a[i];
		readWord(a[i]);
	}
}

inline bool checkSeg(int l, int r, int x) {
	return l <= x && x <= r;
}

inline bool checkLess(int i, int pos1, int pos2) {
	int sz = a[i].size();
	if (pos1 == pos2) return false;
	int pref = min(pos1, pos2);
	int now1 = pref + (pref == pos1);
	int now2 = pref + (pref == pos2);
	if (now1 == sz) return true;
	if (now2 == sz) return false;
	if (a[i][now1] != a[i][now2]) return a[i][now1] < a[i][now2];
	int len1 = nxtDiff[now1] - now1;
	if (checkSeg(now1, now1 + len1, pos1)) len1 = pos1 - 1 - now1;
	int len2 = nxtDiff[now2] - now2;
	if (checkSeg(now2, now1 + len2, pos2)) len2 = pos2 - 1 - now2;
	int len = min(len1, len2);
	now1 += len;
	now2 += len;
	if (now1 == sz) return true;
	if (now2 == sz) return false;
	if (a[i][now1] != a[i][now2]) return a[i][now1] < a[i][now2];
	if (now1 + 1 == pos1) now1 += 2;
	if (now2 + 1 == pos2) now2 += 2;
	if (now1 >= sz) return true;
	if (now2 >= sz) return false;
	if (a[i][now1] != a[i][now2]) return a[i][now1] < a[i][now2];
	len1 = nxtDiff[now1] - now1;
	len2 = nxtDiff[now2] - now2;
	len = min(len1, len2);
	now1 += len;
	now2 += len;
	if (now1 == sz) return true;
	if (now2 == sz) return false;
	return a[i][now1] < a[i][now2];
}

inline void buildNxt(int ind) {
	for (int i = (int)a[ind].size() - 1; i >= 0; --i) {
		nxtDiff[i] = i + 1;
		if (i + 1 < (int)a[ind].size() && a[ind][i] == a[ind][i + 1]) {
			nxtDiff[i] = nxtDiff[i + 1];
		} 
	}
}

inline void build(int i) {
	init(a[i]);
	buildNxt(i);
	iota(order[1], order[1] + a[i].size() + 1, 0);
	stable_sort(order[1], order[1] + a[i].size() + 1, [&] (int pos1, int pos2) {
		return checkLess(i, pos1, pos2);
	});
}

inline bool checkGood(int ind1, int pos1, int ind2, int pos2) {
	int sz1 = (int)a[ind1].size() - (pos1 < a[ind1].size());
	int sz2 = (int)a[ind2].size() - (pos2 < a[ind2].size());
	int l = 0, r = min(sz1, sz2) + 1;
	while (l < r - 1) {
		int mid = (l + r) >> 1;
		if (getHash(0, mid, pos1) == getHash(1, mid, pos2)) {
			l = mid;
		} else {
			r = mid;
		}
	} 
	if (l == sz1) return true;
	if (l == sz2) return false;
	return a[ind1][l + (l >= pos1)] <= a[ind2][l + (l >= pos2)];
}

inline void swapAll(int len) {
	for (int i = 0; i <= len; i++) {
		dp[0][i] = dp[1][i];
		order[0][i] = order[1][i];
		hash[0][i] = hash[1][i];
	}
}

inline void calcDp() {
	for (int i = 0; i <= (int)a[0].size(); ++i) {
		dp[1][i] = 1;
	}
	build(0);
	for (int i = 1; i < n; ++i) {
		swapAll(a[i - 1].size());
		build(i);
		int sum = 0;
		int pos1 = 0;
		for (int pos2 = 0; pos2 <= (int)a[i].size(); ++pos2) {
			while (pos1 <= (int)a[i - 1].size() && checkGood(i - 1, order[0][pos1], i, order[1][pos2])) {
				sum = add(sum, dp[0][order[0][pos1++]]);
			}
			dp[1][order[1][pos2]] = sum;
		}
	}
}

inline void calcAns() {
	ans = 0;
	for (int i = 0; i <= (int)a[n - 1].size(); ++i) {
		ans = add(ans, dp[1][i]);
	}
}

inline void run() {
	calcDp();
	calcAns();
}

inline void write() {
	//cout << ans << endl;
	writeInt(ans, '\n');
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	prebuild();
	read();
	run();
	write();
	return 0;
}