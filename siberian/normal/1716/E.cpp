#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

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

#define N	18

long long max(long long a, long long b) { return a > b ? a : b; }

int main() {
	static int aa[1 << N];
	static long long ss[1 << N], pp[1 << N], qq[1 << N], ans[1 << N];
	int n, l, q, h, i, j, b;
	l = readInt();
	n = 1 << l;
	for (i = 0; i < n; i++)
		aa[i] = readInt();
	for (i = 0; i < n; i++)
		ss[i] = aa[i], pp[i] = qq[i] = ans[i] = max(aa[i], 0);
	for (h = 0; h < l; h++)
		for (i = 0; i < n; i++)
			if ((i & 1 << h) == 0) {
				long long si, pi, qi, ai, sj, pj, qj, aj;

				j = i ^ 1 << h;
				si = ss[i], pi = pp[i], qi = qq[i], ai = ans[i];
				sj = ss[j], pj = pp[j], qj = qq[j], aj = ans[j];
				ss[i] = si + sj;
				pp[i] = max(pi, si + pj);
				qq[i] = max(qi + sj, qj);
				ans[i] = max(max(ai, aj), qi + pj);
				ss[j] = sj + si;
				pp[j] = max(pj, sj + pi);
				qq[j] = max(qj + si, qi);
				ans[j] = max(max(aj, ai), qj + pi);
			}
	q = readInt();
	b = 0;
	while (q--) {
		h = readInt();
		b ^= 1 << h;
		writeInt(ans[b], '\n');
	}
	return 0;
}