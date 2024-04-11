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

int n, d, h; 

void bad() {
  puts("-1"); 
  exit(0); 
}

vector<pair<int, int> > ans; 

int NEW_V = 1; 
int add(int p) {
  NEW_V++; 
  ans.pb(mp(p, NEW_V)); 
  return NEW_V; 
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	cin >> n >> d >> h; 
  
    if (2 * h < d) {
      //cerr << "1"; 
      bad(); 
    }

    if (d < h) {
      //cerr << "2"; 
      bad(); 
    }
  
    if (d == 1 && n > 2) {
      //cerr << "3"; 
      bad(); 
    }
    
    int added = 1; 
    int prev = 1;
    int mem = 1; 
    for (int i = 0; i < h; i++) {
      prev = add(prev); 
      if (i != h - 1) mem = prev; 
      added++; 
    }
  
    prev = 1; 
    for (int i = 0; i < d - h; i++) {
      prev = add(prev); 
      added++; 
    }
  
    if (added > n) {
      bad(); 
    }
  
    for (int i = 0; i < n - added; i++) {
      add(mem); 
    }
  
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << "\n"; 
    }

    return 0;
}