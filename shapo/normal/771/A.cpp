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

const int maxn = 300000; 
int n, m; 
vector<int> a[maxn]; 
ll h[maxn], h2[maxn]; 

const int MOD = 1000000007; 
const int MOD2 = 1000000009; 
const ll MUL = 163841; 
const ll MUL2 = 176081; 

int main()
{
  //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	
  int n, m; 
  scanf("%d %d", &n, &m); 
  
  for (int i = 0; i < n; i++) {
    a[i].pb(i); 
  }
  
  for (int i = 0; i < m; i++) {
    int x, y; 
    scanf("%d %d", &x, &y); 
    x--, y--; 
    a[x].pb(y); 
    a[y].pb(x); 
  }
  
  for (int i = 0; i < n; i++) {
    sort(a[i].begin(), a[i].end()); 
    h[i] = 42; 
    h2[i] = 37; 
    for (int j = 0; j < a[i].size(); j++) {
      h[i] = (h[i] * MUL + a[i][j]) % MOD; 
      h2[i] = (h2[i] * MUL2 + a[i][j]) % MOD2; 
    }
    
    //cerr << i << " " << h[i] << " " << h2[i] << endl; 
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      int to = a[i][j]; 
      if (h[i] != h[to] || h2[i] != h2[to]) {
        cout << "NO" << endl; 
        return 0; 
      }
    }
  }
  
  cout << "YES" << endl;
  return 0;
}