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

int main()
{
  //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false); 
  
  int t; 
  cin >> t; 
  
  for (int tc = 0; tc < t; tc++) {
    ll x, y, p, q; 
    cin >> x >> y >> p >> q; 
    
    if (p == q) {
      if (x == y) {
        cout << 0 << endl; 
      } else {
        cout << -1 << endl; 
      }
      continue; 
    }
    
    if (p == 0) {
      if (x == 0) {
        cout << 0 << endl; 
      } else {
        cout << -1 << endl; 
      }
      continue;
    }
    
    ll l = -1, r = 5LL*1000000000; 
    while (r - l > 1) {
      ll m = (r + l) / 2;
      
      if (m * q >= y && m * p >= x && (m * q - y) - (m * p - x) >= 0) {
        r = m; 
      } else {
        l = m; 
      }
    }
    
    cout << q * r - y << endl; 
  }
  
  return 0;
}