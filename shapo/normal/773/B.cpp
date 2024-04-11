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

int n;
int solved[5]; 
int a[200][5]; 

bool more(ll nom, ll den, ll x, ll y) {
  return nom * y > den * x; 
}

ll get_score(int i, int j, int acc, int rej) {
  if (a[i][j] == -1) {
    return 0; 
  }
  
  int nom = acc + solved[j]; 
  int den = n + acc + rej; 
  
  if (more(nom, den, 1, 2)) {
    return 500 - 2 * a[i][j];
  } else if (more(nom, den, 1, 4)) {
    return 1000 - 4 * a[i][j];
  } else if (more(nom, den, 1, 8)) {
    return 1500 - 6 * a[i][j]; 
  } else if (more(nom, den, 1, 16)) {
    return 2000 - 8 * a[i][j]; 
  } else if (more(nom, den, 1, 32)) {
    return 2500 - 10 * a[i][j]; 
  } else {
    return 3000 - 12 * a[i][j]; 
  }
}

bool check(ll m) {
  ll score_v = 0, score_p = 0;
  for (int i = 0; i < 5; i++) {
    if (a[0][i] == -1 && a[1][i] == -1) {
      continue;
    }
    
    if (a[0][i] == -1 && a[1][i] != -1) {
      score_v += get_score(0, i, 0, m); 
      score_p += get_score(1, i, 0, m);
      continue;
    }
    
    if (a[0][i] != -1 && a[1][i] == -1) {
      score_v += get_score(0, i, 0, m); 
      score_p += get_score(1, i, 0, m);
      continue;
    }
    
    if (a[0][i] < a[1][i]) {
      score_v += get_score(0, i, 0, m); 
      score_p += get_score(1, i, 0, m);
    } else {
      score_v += get_score(0, i, m, 0); 
      score_p += get_score(1, i, m, 0);
    }
  }
  
  if (score_v > score_p) {
    return 1; 
  } else {
    return 0; 
  }
}

int main()
{
  
  //freopen("input.txt", "r", stdin); //freopen("output2.txt", "w", stdout);
  ios_base::sync_with_stdio(false); 
  
  cin >> n; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j]; 
      if (a[i][j] != -1) {
        solved[j]++; 
      }
    }
  }
  
  for (int i = 0; i < 20000; i++) {
    if (check(i)) {
      cout << i << endl; 
      return 0; 
    }
  }
  
  cout << -1 << endl;
  return 0;
}