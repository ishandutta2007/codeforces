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

int n; 
int cols[maxn]; 
int ans[maxn]; 
int a[maxn];
int maxcol = 0; 
int maxcolcnt = -1; 

void add(int col) {
  cols[col]++; 
  if (cols[col] > maxcolcnt || (cols[col] == maxcolcnt && col < maxcol)) {
    maxcol = col; 
    maxcolcnt = cols[col]; 
  }
}

int main()
{
    //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	
    scanf("%d", &n); 
  
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]); 
    }
  
    for (int i = 0; i < n; i++) {
        maxcolcnt = -1;
      memset(cols, 0, sizeof(cols)); 
      
      for (int j = i; j < n; j++) {
        add(a[j]); 
        ans[maxcol]++; 
      }
    }
  
    for (int i = 1; i <= n; i++) {
      printf("%d ", ans[i]);
    }
    puts(""); 

    return 0;
}