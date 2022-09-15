#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  std::ios::sync_with_stdio(false);
cin.tie(0);
  int n;
  cin >> n;
  vl p3(1000001, 1);
  for (ll i = 1; i < p3.size(); ++i) {
    p3[i] = i * i * i;
  }
  for (int t = 0; t < n; ++t) {
    ll a,b;
    cin >> a >> b;

    ll d = __gcd(a, b);
    ll ab = a / d * b / d;
    if (d % ab || !binary_search(p3.begin(), p3.end(), a * b)) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}