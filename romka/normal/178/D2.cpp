#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int s, n, b[7][7], a[49], used[49], n2;

bool check() {
  forn(i, n) {
    int sr = 0;
    forn(j, n) sr += b[i][j];
    if (sr != s) return false;
    sr = 0;
    forn(j, n) sr += b[j][i];
    if (sr != s) return false;
  }

  int sr = 0;
  forn(i, n) sr += b[i][i];
  if (sr != s) return false;

  sr = 0;
  forn(i, n) sr += b[i][n-1-i];
  if (sr != s) return false;

  return true;
}

void rec(int i, int j, int sr) {
  if (i == n) {
    if (!check()) return;
    forn(q, n) {
      forn(w, n) {
        if (w) printf(" ");
        printf("%d", b[q][w]);
      }
      printf("\n");
    }
    exit(0);
  }

  if (j == n-1) {
    int r1 = s - sr;
    int r2 = r1;
    int r3 = r1;
    if (i == n - 1) {
      r2 = 0, r3 = 0;
      forn(z, n-1) r2 += b[z][z], r3 += b[z][n-1];
      r2 = s - r2, r3 = s - r3;
    }     
    if (r1 != r2 || r1 != r3) return;
    forn(q, n2)
      if (!used[q] && a[q] == r1) {
        used[q] = true;
        b[i][j] = a[q];
        rec(i+1, 0, 0);
        used[q] = false;
        break;
      }
    return;
  }

  if (i == n-1) {
    int sw = 0;
    forn(z, n-1) sw += b[z][j];
    int t1 = s - sw;
    int t2 = t1;
    if (j == 0) {
      int ss = 0;
      forn(z, n-1) ss += b[z][n-1-z];
      t2 = s - ss;
    }

    if (t1 != t2) return;

    forn(q, n2)
      if (!used[q] && a[q] == t1) {
        used[q] = true;
        b[i][j] = a[q];
        rec(i, j+1, sr + a[q]);
        used[q] = false;
      }
    return; 
  }

  int lu = a[0] - 1;
  forn(q, n2)
    if (!used[q] && a[q] != lu) {
      if (i == 0 && j == 2 && a[q] < b[0][1]) continue;
      used[q] = true;
      b[i][j] = lu = a[q];
      rec(i, j+1, sr+lu);
      used[q] = false;
    }
}

int aa(int x) {
  return x < 0 ? -x : x;
}

int main()
{
  scanf("%d", &n);
  n2 = n*n;
  forn(i, n2) scanf("%d", &a[i]);
  sort(a, a+n2);
//  reverse(a, a+n2);
  s = 0;
  forn(i, n2) s += a[i];
  s /= n;
  printf("%d\n", s);
  rec(0, 0, 0);
  return 0;
}