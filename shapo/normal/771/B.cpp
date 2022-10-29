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

vector<string> ss; 
int ans[100]; 
int n, k;

string gen_name(int n) {
  string s; 
  s += ('A' + n / 26);
  s += ('a' + n % 26); 
  return s; 
}


int main()
{
  //freopen("input.txt", "r", stdin); //freopen("output2.txt", "w", stdout);
	
  cin >> n >> k; 
  ss.resize(n - k + 1); 
  
  int yespos = -1; 
  for (int i = 0; i < n - k + 1; i++) {
    cin >> ss[i]; 
    if (ss[i] == "YES") {
      yespos = i; 
    }
  }
  
  if (yespos == -1) {
    for (int i = 0; i < n; i++) {
      cout << gen_name(0) << " "; 
    }
    cout << endl;
    return 0; 
  }
  
  int unique = 0; 
  for (int i = yespos; i < yespos + k; i++) {
    ans[i] = unique++; 
  }
  
  for (int i = yespos + 1; i < n - k + 1; i++) {
    if (ss[i] == "NO") {
      ans[i + k - 1] = ans[i]; 
    } else {
      ans[i + k - 1] = unique++; 
    }
  }
  
  for (int i = yespos - 1; i >= 0; i--) {
    if (ss[i] == "NO") {
      ans[i] = ans[i + k - 1]; 
    } else {
      ans[i] = unique++; 
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << gen_name(ans[i]) << " "; 
  }
  cout << endl;
  
 
  return 0;
}