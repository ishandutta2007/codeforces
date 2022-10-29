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

int n, k, q;
int a[maxn]; 
set<int> vals; 
int opened[maxn]; 

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	scanf("%d %d %d", &n, &k, &q); 
  
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]); 
    }
  
    for (int i = 0; i < q; i++) {
      int type, x; 
      cin >> type >> x; 
      x--; 
      
      if (type == 1) {
        vals.insert(a[x]);
        if (vals.size() > k) {
          vals.erase(vals.begin()); 
        }
        opened[x] = 1; 
      } else {
        if (!opened[x] || vals.empty() || (*vals.begin()) > a[x]) {
          puts("NO"); 
        } else {
          puts("YES"); 
        }
      }
    }

    return 0;
}