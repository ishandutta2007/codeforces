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

const int maxn = 1000000; 

vector<pii> a; 

vector<pii> ans; 
void add(int from, int to) {
  ans.pb(mp(from, to)); 
}

int main()
{
  //freopen("input.txt", "r", stdin); //freopen("output2.txt", "w", stdout);
	
  int n; 
  cin >> n; 
  
  for (int i = 1; i <= n; i++) {
    int x; 
    cin >> x; 
    a.pb(mp(x, i)); 
  }
  
  sort(a.begin() + 1, a.end()); 
  reverse(a.begin() + 1, a.end()); 
      
  int to = 1; 
  for (int i = 0; i < n && to < n && i < to; i++) {
    for (int j = 0; j < a[i].first && to < n; j++) {
      add(a[i].second, a[to].second); 
      to++;
    }
  }
  
  if (to < n) {
    cout << -1 << endl; 
    return 0; 
  }
  
  cout << ans.size() << endl; 
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl; 
  }

  return 0;
}