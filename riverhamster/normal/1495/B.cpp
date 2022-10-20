#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#else
#define File(s)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
  char ch; x = 0;int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> inline void wi(T x){
  static char stk[128]; int top = 0;
  if(x == 0) putchar('0');
  if(x < 0) putchar('-'), x = -x;
  while(x) stk[++top] = x % 10, x /= 10;
  while(top) putchar(stk[top--] + '0');
}
template<class T, class ...Args>
inline void gi(T &x, Args&... args) {gi(x); gi(args...);}
template<class T, class ...Args>
inline void wi(T x, Args... args) {wi(x); SP; wi(args...);}
template<class T> void upmax(T &x, T y) {x = x > y ? x : y;}
template<class T> void upmin(T &x, T y) {x = x < y ? x : y;}

const int N = 100005;
int p[N];
int n;
vector<int> s;

int main(){
  File("b");
  gi(n);
  for (int i = 1; i <= n; ++i) gi(p[i]);
  bool last = p[2] > p[1];
  int now = 1;
  for (int i = 3; i <= n; ++i) {
    bool cur = p[i] > p[i - 1];
    if (cur == last) ++now;
    else {
      s.push_back(now);
      now = 1; last = cur;
    }
  }
  s.push_back(now);
  bool init = p[2] > p[1];
  int mx = *max_element(s.begin(), s.end());
  if (mx & 1) return puts("0"), 0;
  if (count(s.begin(), s.end(), mx) != 2) return puts("0"), 0;
  int p = find(s.begin(), s.end(), mx) - s.begin();
  if (!(init ^ (p & 1))) return puts("0"), 0;
  if (s[p + 1] != mx) return puts("0"), 0;
  puts("1");
  return 0;
}