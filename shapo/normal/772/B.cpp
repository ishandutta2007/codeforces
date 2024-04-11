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

double ans = 1e10; 
int n; 
double x[10000]; 
double y[10000]; 

void upd_ans(double x, double y, double xx, double yy, double xxx, double yyy) {
  double a = y - yyy; 
  double b = xxx - x; 
  double c = -(a * x + b * y); 
  
  assert(abs(a * x + b * y + c) < 1e-6); 
  assert(abs(a * xxx + b * yyy + c) < 1e-6); 
  
  double dd = abs(a * xx + b * yy + c) / sqrt(a * a + b * b); 
  ans = min(ans, dd / 2); 

}

int main()
{
  
  //freopen("input.txt", "r", stdin); //freopen("output2.txt", "w", stdout);
  ios_base::sync_with_stdio(false); 
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i]; 
  }
  
  x[n] = x[0]; 
  y[n] = y[0];
  x[n + 1] = x[1]; 
  y[n + 1] = y[1]; 
  
  for (int i = 0; i < n; i++) {
    upd_ans(x[i], y[i], x[i + 1], y[i + 1], x[i + 2], y[i + 2]); 
  }
  
  cout.precision(42); 
  cout.setf(ios::fixed); 
  
  cout << ans << endl; 
  
  return 0;
}