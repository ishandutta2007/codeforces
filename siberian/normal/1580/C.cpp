#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 2e5 + 10;
const int BUBEN = 1000;

int n, m;
int x[N], y[N];

int small[BUBEN][BUBEN];
int large[N];

int timeAdd[N];

void updFenwick(int pos, int val) {
    for (; pos < m; pos |= pos + 1) {
        large[pos] += val;
    }
}

int getFenwick(int pos) {
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ans += large[pos];
    }
    return ans;
}

void addOnSegmentLarge(int l, int r, int val) {
    if (r < l) return;
    updFenwick(l, val);
    updFenwick(r + 1, -val);
}

void upd(int now, int type, int val) {
    if (val == 1) {
        timeAdd[type] = now;
    } else {
        now = timeAdd[type];
    }
    int mod = x[type] + y[type];
    if (mod < BUBEN) {
        int cur = (x[type] + now) % mod;
        for (int t = x[type]; t < mod; ++t) {
            small[mod][cur] += val;
            cur = (cur < mod - 1 ? cur + 1 : 0); 
        }
    } else {
        for (int t = now + x[type]; t < m; t += mod) {
            addOnSegmentLarge(t, t + y[type] - 1, val);
        }
    }
}

int precalc[BUBEN];

int getAns(int val) {
    int ans = getFenwick(val);
    for (int mod = 2; mod < BUBEN; ++mod) {
        ans += small[mod][precalc[mod]];
        ++precalc[mod];
        if (precalc[mod] == mod) precalc[mod] = 0;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    // cin >> n >> m;
    n = readInt();
    m = readInt();
    for (int i = 0; i < n; ++i) {
        // cin >> x[i] >> y[i];
        x[i] = readInt();
        y[i] = readInt();
    }
    for (int i = 0; i < m; ++i) {
        int op, k;
        // cin >> op >> k;
        op = readInt();
        k = readInt();
        --k;
        if (op == 1) {
            upd(i, k, 1);
        } else if (op == 2) {
            upd(i, k, -1);
        } else {
            assert(false);
        }
        writeInt(getAns(i), '\n');
        // cout << getAns(i) << '\n';
    }
    return 0;
}