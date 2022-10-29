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

const int maxn = 200000; 

int n; 
char s[maxn]; 
int a[maxn]; 
int used[maxn]; 

int main()
{
    //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	
	scanf("%d", &n); 
    scanf("%s", s);
  
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]); 
    }
  
    int p = 0; 
    while (p >= 0 && p < n && !used[p]) {
      used[p] = 1; 
      p += a[p] * (s[p] == '>' ? 1 : -1); 
    }

  
    if (p < 0 || p >= n) {
      puts("FINITE");
    } else {
      puts("INFINITE");
    }

    return 0;
}