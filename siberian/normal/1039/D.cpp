#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,mmx,abm")
//#pragma GCC optimize("inline")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define FAST_ALLOCATOR_MEMORY 10 * 1024 * 1024
#ifdef FAST_ALLOCATOR_MEMORY
int ptr = 0;
char memory[(int) FAST_ALLOCATOR_MEMORY];
 
inline void *operator new(size_t n) {
	char *res = memory + ptr;
	ptr += n;
	return (void *)  res; 
}  
  
inline void operator delete(void *) noexcept {}
inline void operator delete(void *, size_t) {}
#endif

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
	 
	inline void readWord(char *s) { 
		int c = readChar();
		while (c > 32)
			*s++ = c, c = getChar();
		*s = 0;
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

const int MAXN = 1e5 + 230;
int n;
vector<int> g[MAXN];
int deg[MAXN];

void read() {
	n = readInt();
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		u = readInt();
		v = readInt();
		u--;
		v--;
		deg[u]++;
		deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int p[MAXN];

int mem[MAXN];
int tin[MAXN], timer = 0;
int len[MAXN];
int cost[MAXN];

void dfs_tin(int v, int pv, int last_good) {
	if (v == 0 || deg[v] != 2) {
		tin[v] = timer++;
		len[v] = 0;
		cost[tin[v]] = len[pv] + 1;
		p[tin[v]] = last_good;
		last_good = tin[v];
	} else {
		len[v] = len[pv] + 1;
	}
	for (auto i : g[v]) {
		if (i == pv) continue;
		dfs_tin(i, v, last_good);
 	}
}

void build() {
	for (int i = 1; i <= n; i++)
		mem[i] = -1;
	dfs_tin(0, 0, 0);
	reverse(p, p + timer);
	reverse(cost, cost + timer);
	for (int i = 0; i < timer; i++)
		p[i] = timer - 1 - p[i];
}

int res;
int need[MAXN];
int val[MAXN];

void dfs(int k) {
	if (k == 1) {
		res = n;
		return;
	}
	res = 0;
	for (int v = 0; v < timer; v++) {
		if (need[v]) {
			res++;
			val[v] = -1;
		} 
		val[v] += cost[v];
		while (val[v] >= k)
			res++, val[v] -= k;
		if (val[v] + val[p[v]] + 1 >= k) {
			need[p[v]] = 1;
		}
		if (val[v] > val[p[v]]) {
			val[p[v]] = val[v];
		}
		need[v] = val[v] = 0;
	}
}

int calc(int k) {
	dfs(k);
	return res;
}

int ans[MAXN];

void solve(int lk, int rk, int min_val, int max_val) {
	chkmin(max_val, n / lk);
	if (min_val == max_val) {
		for (int i = lk; i <= rk; i++) {
			ans[i] = min_val;
		}
		return;
	}
	int mk = (lk + rk) >> 1;
	ans[mk] = calc(mk);
	if (lk <= mk - 1) {
		solve(lk, mk - 1, ans[mk], max_val);
	}
	if (mk + 1 <= rk) {
		solve(mk + 1, rk, min_val, ans[mk]);
	}
}

void run() {
	build();
	solve(1, n, 0, n);
}

void write() {
	for (int i = 1; i <= n; i++) {
		writeInt(ans[i], '\n');
	}
}

signed main() {
	read();
	run();
	write();
	return 0;
}