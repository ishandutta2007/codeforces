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

const int maxn = 100000; 
int m[maxn]; 
int n, k, a, b, c, d;

int main()
{
    //freopen("input.txt", "r", stdin); //freopen("output2.txt", "w", stdout);
	
    int n, k; 
    scanf("%d %d", &n, &k); 
    if (n == 4 || k <= n) {
      printf("%d\n", -1); 
      return 0; 
    }
    
    scanf("%d %d %d %d", &a, &b, &c, &d); 
    a--, b--, c--, d--; 
    
    m[0] = a; 
    m[1] = c; 
    int j = 0; 
    for (int i = 2; i < n - 2; i++) {
      while (j == a || j == b || j == c || j == d) j++; 
      m[i] = j; 
      j++; 
    }
    m[n - 2] = d; 
    m[n - 1] = b; 
  
    for (int i = 0; i < n; i++) {
      printf("%d ", m[i] + 1); 
    }
    
    puts(""); 
  
    printf("%d %d ", c + 1, a + 1); 
    for (int i = 2; i < n - 2; i++) {
      printf("%d ", m[i] + 1); 
    }
    printf("%d %d", b + 1, d + 1);
  
    puts(""); 

    return 0;
}