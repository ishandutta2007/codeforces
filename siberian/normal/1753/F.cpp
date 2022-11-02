#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull  = unsigned long long;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x) {
        x = y;
    }
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) {
        x = y;
    }
}

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

// #define FAST_ALLOCATOR_MEMORY 100 * 1024 * 1024
// #ifdef FAST_ALLOCATOR_MEMORY
// int ptr = 0;
// char memory[(int) FAST_ALLOCATOR_MEMORY];
 
// inline void *operator new(size_t n) {
//     char *res = memory + ptr;
//     ptr += n;
//     return (void *)  res; 
// }  
  
// inline void operator delete(void *) noexcept {}
// inline void operator delete(void *, size_t) {}
// #endif

constexpr int C = 1e6;
constexpr int N = 40000;
constexpr int LOG = 8;
constexpr int B = 1 << LOG;

int cnt[2][C];
int cntBlock[2][C / B + 5];
bitset<B> usedPos[2][C / B + 5];
bitset<C / B + 5> usedBlocks[2];
int sz[2];

void upd(int id, int pos, int val) {
    if (cnt[id][pos] == 0 && val == 1) {
        int blockId = pos >> LOG;
        cntBlock[id][blockId]++;
        if (cntBlock[id][blockId] == B) {
            usedBlocks[id][blockId] = 0;
        }
        usedPos[id][blockId][pos & (B - 1)] = 0;
    } else if (cnt[id][pos] == 1 && val == -1) {
        int blockId = pos >> LOG;
        if (cntBlock[id][blockId] == B) {
            usedBlocks[id][blockId] = 1;
        }
        cntBlock[id][blockId]--;
        usedPos[id][blockId][pos & (B - 1)] = 1;
    }
    cnt[id][pos] += val;
}

int getMex(int id) {
    int blockId = usedBlocks[id]._Find_first();
    // int pos = usedPos[id]._Find_next((blockId << LOG) - 1);
    int pos = usedPos[id][blockId]._Find_first() + (blockId << LOG);
    return pos;
}

int n, m, k, t;
vector<vector<int>> vals[N];
int coord[2][C];
int top[2];

void compress() {
    for (int it = 0; it < 2; ++it) {
        stable_sort(coord[it], coord[it] + top[it]);
        top[it] = unique(coord[it], coord[it] + top[it]) - coord[it];
        for (int i = 1; i < top[it]; ++i) {
            if (coord[it][i] - 1 > coord[it][i - 1]) {
                top[it] = i;
                break;
            }
        }
        sz[it] = top[it] + 1;
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (vals[x][y].empty()) {
                continue;
            }
            // sort(all(vals[x][y]));
            vector<int> nvals;
            nvals.reserve(vals[x][y].size());
            for (const int val : vals[x][y]) {
                if (val >= 0) {
                    int pos = lower_bound(coord[0], coord[0] + top[0], val) - coord[0];
                    if (pos < top[0]) {
                        nvals.push_back(pos);
                    }
                } else {
                    int pos = lower_bound(coord[1], coord[1] + top[1], -val) - coord[1];
                    if (pos < top[1]) {
                        nvals.push_back(-(pos + 1));
                    }
                }
            }
            stable_sort(all(nvals));
            vals[x][y].swap(nvals);
        }
    }
}

void updVal(int val, int flag) {
    if (val >= 0) {
        upd(0, val, flag);
    } else {
        upd(1, -(val + 1), flag);
    }
}

bool ok() {
    int cnt0 = getMex(0);
    int cnt1 = getMex(1);
    return cnt0 + cnt1 >= t - 1;
}

void addCell(int lx, int ly, int rx, int ry) {
    // cerr << "lx = " << lx << " ly = " << ly << " rx = " << rx << " ry = " << ry << endl;
        
    for (int x = lx; x <= rx; ++x) {
        for (const int val : vals[x][ry]) {
            updVal(val, 1);
        }
    }
    for (int y = ly; y < ry; ++y) {
        for (const int val : vals[rx][y]) {
            updVal(val, 1);
        }
    }
}

void removeCell(int lx, int ly, int rx, int ry) {

    for (int x = lx; x <= rx; ++x) {
        for (const int val : vals[x][ly]) {
            updVal(val, -1);
        }
    }
    for (int y = ly + 1; y <= ry; ++y) {
        for (const int val : vals[lx][y]) {
            updVal(val, -1);
        }
    }
}

ll solve(int x, int y) {
    int lx, ly;
    int rx, ry;
    ll ans = 0;
    lx = x, ly = y;
    rx = x - 1, ry = y - 1;

    while (lx < n && ly < m && rx < n && ry < m) {
        bool last_ok = ok();
        while (rx + 1 < n && ry + 1 < m && !last_ok) {
            ++rx;
            ++ry;
            addCell(lx, ly, rx, ry);
            last_ok = ok();
        }
        if (!last_ok) {
            break;
        }
        // cerr << "lx = " << lx << " ly = " << ly << " rx = " << rx << " ry = " << ry << endl;
        ans += min(n - rx, m - ry);
        removeCell(lx, ly, rx, ry);
        ++lx;
        ++ly;
    }

    while (lx <= rx) {
        removeCell(lx, ly, rx, ry);
        ++lx;
        ++ly;
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    // cin >> n >> m >> k;
    // cin >> t;
    n = readInt();
    m = readInt();
    k = readInt();
    t = readInt();
    top[0] = top[1] = 0;
    usedBlocks[0].set();
    usedBlocks[1].set();
    // usedPos[0].set();
    // usedPos[1].set();
    for (int blockId = 0; blockId < C / B + 5; ++blockId) {
        usedPos[0][blockId].set();
        usedPos[1][blockId].set();
    } 
    for (int i = 0; i < n; ++i) {
        vals[i].assign(m, vector<int>());
    }
    coord[0][top[0]++] = 1;
    coord[1][top[1]++] = 1;
    for (int i = 0; i < k; ++i) {
        int x, y, val;
        // cin >> x >> y >> val;
        x = readInt();
        y = readInt();
        val = readInt();
        --x;
        --y;
        vals[x][y].push_back(val);
        if (val > 0) {
            coord[0][top[0]++] = val;
        } else {
            coord[1][top[1]++] = -val;
        }
    }
    if (t == 1) {
        ll ans = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                ans += min(n - x, m - y);
            } 
        }
        // cout << ans << '\n';
        writeInt(ans);
        exit(0);
    }
    compress();
    ll ans = 0;
    for (int x = 0; x < n; ++x) {
        ans += solve(x, 0);
    }
    for (int y = 1; y < m; ++y) {
        ans += solve(0, y);
    }
    // cout << ans << endl;
    writeInt(ans);
    return 0;
}