#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <complex>
#include <bitset>
#include <numeric>

using namespace std;

#define mod 1000000007


const int maxN = 201000;
char s[maxN];
char t[maxN];

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int n;
  scanf("%d\n", &n);
  gets(s);
  gets(t);

  long long result1 = 1;
  long long result2 = 1;
  long long result3 = 1;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '?' && t[i] == '?') result2 *= 10; else
    if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) result2 = 0;
    result2 %= mod;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == '?' && t[i] == '?') {
      result1 *= 55LL;
      result3 *= 55LL;
    } else
    if (s[i] != '?' && t[i] != '?') {
      if (s[i] > t[i]) {
        result1 = 0;
      }
      if (s[i] < t[i]) {
        result3 = 0;
      }
    } else {
      if (s[i] == '?' && t[i] != '?') {
        result1 *= (long long)(t[i] - '0' + 1);      
        result3 *= (long long)(10 - (t[i] - '0'));
      } else if (s[i] != '?' && t[i] == '?') {
        result3 *= (long long)(s[i] - '0' + 1);      
        result1 *= (long long)(10 - (s[i] - '0'));
      }
    }
    result1 %= mod;
    result3 %= mod;
  }    

  long long ans = result1 + result3 - result2;
  ans = ((ans % mod) + mod) % mod;

  long long tres = 1LL;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') tres *= 10LL;
    if (t[i] == '?') tres *= 10LL;
    tres %= mod;
  }

  ans = ((tres - ans) % mod + mod) % mod;

  cout << ans << endl;

  return 0;
}