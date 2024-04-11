#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define PLOT(...)
#define CHECK(...)
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

#define FAST_ALLOCATOR_MEMORY 120 * 1024 * 1024
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

namespace {

using LL = long long;
template<typename T, typename U> bool enlarge(T& a, U b) { \
  return a < b ? (a = b, true) : false; }
template<typename T, typename U> bool minify(T& a, U b) { \
  return a > b ? (a = b, true) : false; }

struct Point {
  LL x, y;

  explicit Point(LL x = 0, LL y = 0) : x(x), y(y) {}

  Point operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
  }
};

__int128 det(const Point& lhs, const Point& rhs) {
  return __int128(lhs.x) * rhs.y - __int128(lhs.y) * rhs.x;
}

__int128 det(const Point& a, const Point& b, const Point& c) {
  return det(b - a, c - a);
}

LL dot(const Point& lhs, const Point& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

struct Edge {
  int v, w;
};

const LL inf = 9e18;

template<typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

struct Solver {

  void solve(int ca/*, std::istream& reader*/) {
    int N, M, K;
    // reader >> N >> M >> K;
    N = readInt();
    M = readInt();
    K = readInt();
    std::vector<std::vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
      int x, y, z;
      // reader >> x >> y >> z; --x; --y;
      x = readInt();
      y = readInt();
      z = readInt();
      --x;
      --y;
      graph[x].emplace_back(Edge{.v = y, .w = z});
      graph[y].emplace_back(Edge{.v = x, .w = z});
    }
    std::vector<LL> dist(N, inf);

    MinPQ<std::pair<LL, int>> pq;

    auto dijkstra = [&]() -> void {
      while (!pq.empty()) {
        auto [tmp, u] = pq.top(); pq.pop();
        if (tmp != dist[u]) continue;
        for (const Edge& e : graph[u]) {
          if (minify(dist[e.v], dist[u] + e.w)) {
            pq.emplace(dist[e.v], e.v);
          }
        }
      }
    };

    dist[0] = 0;
    pq.emplace(0LL, 0);
    dijkstra();

    for (int iteration = 0; iteration < K; ++iteration) {
      std::vector<Point> stack;
      for (int i = 0; i < N; ++i) if (dist[i] != inf) {
        Point p(-2 * i, i * 1LL * i + dist[i]);
        while (stack.size() >= 2 &&
               det(p, stack.back(), stack.end()[-2]) <= 0) {
          stack.pop_back();
        }
        stack.emplace_back(p);
      }
      for (int i = 0, j = 0; i < N; ++i) {
        Point p(i, 1);
        while (j + 1 < stack.size() &&
               dot(p, stack[j]) > dot(p, stack[j + 1])) {
          ++j;
        }
        while (j > 0 &&
               dot(p, stack[j]) > dot(p, stack[j - 1])) {
          --j;
        }
        if (minify(dist[i], i * 1LL * i + dot(p, stack[j]))) {
          pq.emplace(dist[i], i);
        }
      }
      dijkstra();
    }
    for (int i = 0; i < N; ++i) {
      // printf("%lld%c", dist[i], " \n"[i + 1 == N]);
      writeInt(dist[i], " \n"[i + 1 == N]);
    }
  }
};

}  // namespace

int main() {
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::istream& reader = std::cin;

  int cas = 1;
  // reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca/*reader*/);
  }
}