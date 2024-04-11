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

const int maxn = 10000; 

int main()
{
  //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	
  int n; 
  int s = 0; 
  cin >> n; 
  
  for (int i = 0; i < n; i++) {
    int x; 
    cin >> x; 
    s += x; 
  }
  
  assert(s % n == 0); 
  cout << s / n << endl; 

  return 0;
}