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

int n, m, q; 
int b[maxn][4]; 
int a[200][200];


void print() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d ", a[i][j]); 
      }
      printf("\n"); 
    }
}

int main()
{
    //freopen("input.txt", "r", stdin); //freopen("output2.txt", "w", stdout);
	
    scanf("%d %d %d", &n, &m, &q); 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = -1; 
      }
    }
  
    for (int i = 0; i < q; i++) {
      scanf("%d", &b[i][0]); 
      int bb = 1; 
      if (b[i][0] == 3) {
        bb = 3; 
      }
      for (int j = 0; j < bb; j++) {
        scanf("%d", &b[i][j + 1]); 
      }
    }
  
    for (int i = q - 1; i >= 0; i--) {
      //print(); 
      //puts(""); 
      if (b[i][0] == 3) {
        int r, c, x; 
        r = b[i][1], c = b[i][2], x = b[i][3]; 
        r--, c--; 
        //cout << "set " << r << " " << c << " " << x << "\n"; 
        a[r][c] = x; 
      } 
      
      if (b[i][0] == 2) {
        int c = b[i][1]; 
        c--; 
        for (int i = n - 2; i >= 0; i--) {
          swap(a[i][c], a[i + 1][c]); 
        }
      }
      
      if (b[i][0] == 1) {
        int r = b[i][1]; 
        r--; 
        for (int j = m - 2; j >= 0; j--) {
          swap(a[r][j], a[r][j + 1]); 
        }
      }
    }
  
    print(); 

    return 0;
}