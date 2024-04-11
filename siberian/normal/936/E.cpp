#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

//#define FAST_ALLOCATOR_MEMORY 150 * 1024 * 1024
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

const int INF = 1e9 + 228 + 1337;

struct fenvik{
	vector<int> tree;
	int n;
	fenvik() {}
	fenvik(int sz) {
		n = sz;
		tree.assign(n, INF);
	}
	void upd(int pos, int val) {
		for (; pos < n; pos |= pos + 1)
			chkmin(tree[pos], val);
	}
	int get(int r) {
		int ans = INF;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			chkmin(ans, tree[r]);
		return ans;
	}
};

struct dsu{
	vector<int> par;
	int n;
	dsu() {}
	dsu(int _n) {
		n = _n;
		par.resize(n);
		iota(all(par), 0);
	}
	int get_par(int v) {
		if (v == par[v]) return v;
		return par[v] = get_par(par[v]);
	}
	void uni(int a, int b) {
		a = get_par(a);
		b = get_par(b);
		if (a == b) return;
		par[a] = b;
	}
};

struct fdist{
	int dist, pos;
	fdist() {}
	fdist(int _dist, int _pos) {
		dist = _dist;
		pos = _pos;
	}
};

struct pt{
	int x, y, ind;
	pt() {}
	pt(int _x, int _y) {
		x = _x, y = _y;
	}
};

bool operator<(const pt & a, const pt & b) {
	return tie(a.x, a.y) < tie(b.x, b.y);
}

bool operator==(const pt & a, const pt & b) {
	return tie(a.x, a.y) == tie(b.x, b.y);
}

bool operator!=(const pt & a, const pt & b) {
	return tie(a.x, a.y) != tie(b.x, b.y);
}

const int MAXN = 3e5 + 10, MAXLOG = 19;
int n;
vector<pt> a;
vector<int> g[MAXN], help_graph[MAXN];
int Ind1[MAXN];
vector<pt> vert[MAXN];

int g_size;
int sz[MAXN];
bool used[MAXN];
int centr;
int par[MAXN];
int h[MAXN];
fdist dist[MAXN][MAXLOG];
fenvik fans[MAXN][2];

vector<int> ans;

void read() {
	//cin >> n;
	n = readInt();
	a.resize(n);
	for (auto &i : a) {
		i.x = readInt();
		i.y = readInt();
		//cin >> i.x >> i.y;
	}
	sort(all(a));
	for (int i = 0; i < n; i++) {
		a[i].ind = i;
	}
}

int get_ind(pt x) {
	int pos = lower_bound(all(a), x) - a.begin();
	if (pos == n) return -1;
	return pos;
}

void build_ind() {
	dsu have(n);
	for (int i = 0; i < n; i++) {
		int nx = a[i].x + 1;
		int ny = a[i].y;
		int pos = get_ind({nx, ny});
		if (pos == -1 || a[pos] != pt(nx, ny)) continue;
		have.uni(pos, i);
		help_graph[pos].push_back(i);
		help_graph[i].push_back(pos);
	}
	vector<int> coord;
	for (int i = 0; i < n; i++) {
		coord.push_back(have.get_par(i));
	}
	sort(all(coord));
	coord.resize(unique(all(coord)) - coord.begin());
	for (int i = 0; i < n; i++) {
		Ind1[i] = lower_bound(all(coord), have.get_par(i)) - coord.begin();
		vert[Ind1[i]].push_back(a[i]);
	}
	g_size = coord.size();

	for (int i = 0; i < g_size; i++) {
		sort(all(vert[i]));
	}

	for (int i = 0; i < n; i++) {
		int nx = a[i].x;
		int ny = a[i].y + 1;
		int pos = get_ind({nx, ny});
		if (pos == -1 || a[pos] != pt(nx, ny)) continue;
		help_graph[i].push_back(pos);
		help_graph[pos].push_back(i);
		g[Ind1[i]].push_back(Ind1[pos]);
		g[Ind1[pos]].push_back(Ind1[i]);
	}
	for (int i = 0; i < g_size; i++) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
	}
}

void dfs_centroid(int v, int p, int H, int size) {
	sz[v] = 1;
	int mx = 0;
	for (auto i : g[v]) {
		if (i == p) continue;
		if (used[i]) continue;
		dfs_centroid(i, v, H, size);
		chkmax(mx, sz[i]);
		sz[v] += sz[i];
	}
	chkmax(mx, size - sz[v]);
	if (mx <= size / 2) {
		centr = v;
	}
}

void calc_dist(int v, int H) {
	queue<int> q;
	for (int i = 0; i < (int)vert[v].size(); i++) {
		q.push(vert[v][i].ind);
		dist[vert[v][i].ind][H] = {0, i};
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto i : help_graph[v]) {
			if (used[Ind1[i]]) continue;
			if (dist[i][H].dist < INF) continue;
			q.push(i);
			dist[i][H] = dist[v][H];
			dist[i][H].dist++;
		}
	}
}

void find_centroid(int v, int p, int H, int size) {
	dfs_centroid(v, -1, H, size);
	v = centr;
	par[v] = p;
	used[v] = true;
	calc_dist(v, H);
	h[v] = H++;
	for (auto i : g[v]) {
		if (used[i]) continue;
		int fsz = sz[i];
		if (fsz > sz[v]) {
			fsz = size - sz[v];
		}
		find_centroid(i, v, H, fsz);
	}
}

void build_centroid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAXLOG; j++) {
			dist[i][j] = {INF, -1};
		}
	}
	find_centroid(0, -1, 0, g_size);
}

void build_tree() {
	for (int i = 0; i < g_size; i++) {
		for (int j = 0; j < 2; j++) {
			fans[i][j] = fenvik((int)vert[i].size());
		}
	}
}

void build() {
	build_ind();
	build_centroid();
	build_tree();
}

void upd(int v) {
	int p = Ind1[v];
	for (int i = h[p]; i >= 0; i--) {
		auto & now = dist[v][i];
		fans[p][0].upd(now.pos, now.dist - now.pos);
		fans[p][1].upd(fans[p][1].n - 1 - now.pos, now.dist + now.pos);
		p = par[p];
	}
}

int get(int v) {
	int ans = INF;
	int p = Ind1[v];
	for (int i = h[p]; i >= 0; i--) {
		int have;
		auto & now = dist[v][i];
		have = fans[p][0].get(now.pos);
		if (have < INF) {
			chkmin(ans, have + now.pos + now.dist);
		}
		have = fans[p][1].get(fans[p][1].n - 1 - now.pos);
		if (have < INF) {
			chkmin(ans, have - now.pos + now.dist);
		}
		p = par[p];
	}

	if (ans == INF) ans = -1;
	return ans;
}

void run() {
	build();
	int q;
	//cin >> q;
	q = readInt();
	while (q--) {
		int type;
		//cin >> type;
		type = readInt();
		pt x;
		//cin >> x.x >> x.y;
		x.x = readInt();
		x.y = readInt();
		int pos = get_ind(x);
		if (type == 1) {
			upd(pos);
		} else {
			ans.push_back(get(pos));
		}
	}
}

void write() {
	for (auto i : ans) {
		writeInt(i, '\n');
		//cout << i << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}