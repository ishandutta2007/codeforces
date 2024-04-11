#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
int read_int(){int c,r;while((c=getchar())<48);r=c-48;while((c=getchar())>47)r=r*10+c-48;return r;}
void write_int(int x){int b[10],*p=b;do*p++=48+x%10,x/=10;while(x);do putchar(*--p);while(p>b);}

using BS = bitset<7001>;

int main() {
  V<BS> mask(7000);
  for (int v = 1; v <= 7000; ++v) {
    mask[v][v] = true;
  }
  for (int v = 7000; v >= 1; --v) {
    for (int i = 2 * v; i <= 7000; i += v) {
      mask[v] ^= mask[i];
    }
  }
  V<BS> divs(7000);
  for (int v = 1; v <= 7000; ++v) {
    for (int i = 1; i <= v; ++i) if (v % i == 0) {
      divs[v][i] = true;
    }
  }
  int n = read_int(), q = read_int();
  V<BS> bs(n);
  while (q--) {
    int type = read_int();
    if (type == 1) {
      int x = read_int() - 1, v = read_int();
      bs[x] = divs[v];
    } else if (type == 2) {
      int x = read_int() - 1, y = read_int() - 1, z = read_int() - 1;
      bs[x] = bs[y] ^ bs[z];
    } else if (type == 3) {
      int x = read_int() - 1, y = read_int() - 1, z = read_int() - 1;
      bs[x] = bs[y] & bs[z];
    } else {
      int x = read_int() - 1, v = read_int();
      int c = (bs[x] & mask[v]).count();
      putchar('0' + (c & 1));
    }
  }
  putchar('\n');
}