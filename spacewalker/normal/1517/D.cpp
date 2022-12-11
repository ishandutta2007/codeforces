#include <bits/stdc++.h>

using namespace std;

constexpr int NMAX = 501;
constexpr int INF = 1000000000;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;


// U L D R
int exhibits[NMAX][NMAX][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

//int minDist[NMAX][NMAX][22][22];
int minDist[22][22];
constexpr int OFFSET = 10;

int main() {
    int n, m, k;
    n = readInt();
    m = readInt();
    k = readInt();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int x = readInt();
            exhibits[i][j][1] = exhibits[i][j + 1][3] = x;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = readInt();
            exhibits[i][j][2] = exhibits[i+1][j][0] = x;
        }
    }
    if (k % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("-1 ");
            }
            printf("\n");
        }
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            memset(minDist, 0x3f, sizeof minDist);
            minDist[OFFSET][OFFSET] = 0;
            for (int step = 1; step <= k / 2; ++step) {
                for (int d1 = -step; d1 <= step; ++d1) {
                    int lb = step - abs(d1);
                    for (int d2 = -lb; d2 <= lb; d2 += 2) {
                        int c = INF;
                        int ri = i + d1, rj = j + d2;
                        if (ri < 0 || n <= ri || rj < 0 || m <= rj) continue;
                        for (int mt = 0; mt < 4; ++mt) {
                            int ni = ri + dx[mt], nj = rj + dy[mt];
                            if (ni < 0 || n <= ni || nj < 0 || m <= nj
                                    || d1+dx[mt]+OFFSET < 0 || d2+dy[mt]+OFFSET < 0) continue;
                            c = min(c, minDist[d1+dx[mt]+OFFSET][d2+dy[mt]+OFFSET]
                                    + exhibits[ri][rj][mt]);
                        }
                        minDist[d1+OFFSET][d2+OFFSET] = c;
                    }
                }
            }
            int ans = INF;
            int step = k / 2;
            for (int d1 = -step; d1 <= step; ++d1) {
                int lb = step - abs(d1);
                for (int d2 = -lb; d2 <= lb; d2 += 2) {
                    int ri = i + d1, rj = j + d2;
                    if (ri < 0 || n <= ri || rj < 0 || m <= rj) continue;
                    ans = min(ans, 2 * minDist[d1+OFFSET][d2+OFFSET]);
                }
            }
//            printf("%d ", ans);
            writeInt(ans);
            writeChar(' ');
        } // kdsf
//        printf("\n");
        writeChar('\n');
    }
    return 0;
}