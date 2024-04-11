#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

const int maxn = 2000; 
const int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0}; 
const char let[5] = "DLRU"; 

int n, m, k, sx, sy; 
bool used[maxn][maxn]; 
char a[maxn][maxn]; 
int d[maxn][maxn]; 

int queue[maxn * maxn * 2]; 
int head, tail; 

void add(int x, int y, int dd) {
  if (x < 0 || x >= n || y < 0 || y >= m) return; 
  if (a[x][y] == '*') return; 
  if (used[x][y]) return; 
  used[x][y] = 1; 
  d[x][y] = dd; 
  queue[head++] = x; 
  queue[head++] = y; 
}

bool can(int x, int y, int k) {

  if (x < 0 || x >= n || y < 0 || y >= m) return 0; 
  if (a[x][y] == '*') return 0; 
  
  int dd = d[x][y]; 
  if (dd > k) {
    return 0; 
  }
  
  if ((k - dd) % 2) {
    return 0; 
  }
  
  return 1; 
}

//bool can(int x, int y, int k) {
//  cerr << "called can " << x << " " << y << " " << k << endl; 
//  cerr << "result " << cann(x, y, k) << endl ; 
//  return cann(x, y, k); 
//}

int main()
{
  // freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    
  scanf("%d %d %d", &n, &m, &k); 
  
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]); 
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'X') {
        sx = i; 
        sy = j; 
      }
    }
  }
  
  add(sx, sy, 0); 
  while (head > tail) {
    int x = queue[tail++]; 
    int y = queue[tail++]; 
    
    for (int i = 0; i < 4; i++) {
      add(x + dx[i], y + dy[i], d[x][y] + 1); 
    }
  }
  
//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j < m; j++) {
//      if (!used[i][j]) {
//        cout << "*"; 
//      } else {
//        cout << d[i][j]; 
//      }
//    }
//    cout << endl; 
//  }
  
  string ans; 
  int x = sx, y = sy; 
  while (k > 0) {
    bool okk = false; 
    for (int j = 0; j < 4; j++) {
      if (can(x + dx[j], y + dy[j], k - 1)) {
        ans += let[j]; 
        okk = true; 
        k--; 
        x += dx[j]; 
        y += dy[j]; 
        //cerr << "moving to " << x << " " << y << ", result is now " << ans << endl; 
        break; 
      }
    }
  
    if (!okk) {
      cout << "IMPOSSIBLE\n"; 
      return 0; 
    }
  }

  cout << ans << endl; 
  
  return 0;
}