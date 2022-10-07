#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
const int MAXN = 200200;
pii ar[MAXN];
int n;

int zeros(ll i) {
  int ans = 0;
  while (i && i % 2 == 0) {
    ++ans;
    i /= 2;
  }
  return ans;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    ar[i] = pii(zeros(x), -x);
  }
  sort(ar, ar + n);
  for(int i = 0; i < n; ++i) {
    cout << -ar[i].second << " ";
  }
  cout << "\n";
}