#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool prime[1000001];
  memset(prime, true, sizeof(prime));
  vector<int> primeSet;

  for (int p=2; p<=1000000; p++)
    if (prime[p]) {
      primeSet.push_back(p);
      if (p < 1000)
        for (int i=p*p; i<=1000000; i+=p)
          prime[i] = false;
    }

  int n;
  long long a;
  cin >> n >> a;
  unordered_map<long long, long long> primeFactors;
  for (int i=0; i<primeSet.size() && primeSet[i]<=sqrt(a); i++)
    while (a % primeSet[i] == 0) {
      primeFactors[primeSet[i]]++;
      a /= primeSet[i];
    }
  if (a > 1)
    primeFactors.insert(make_pair(a, 1));

  for (int i=1; i<n; i++) {
    cin >> a;
    for (auto p : primeFactors) {
      long long div = 0;
      while (a % p.first == 0) {
        div++;
        a /= p.first;
      }
      primeFactors[p.first] = min(p.second, div);
    }
  }

  long long ret = 1;
  for (auto p : primeFactors)
    ret *= (p.second + 1);
  cout << ret << "\n";

  return 0;
}