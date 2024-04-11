#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) int((x).size())
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      set<int> f;
      for (int i = 1; i * i <= n; ++i) {
         if (n % i == 0) f.insert(i);
         int j = n / i;
         if (n % j == 0) f.insert(j);
      }
      f.erase(1);
      vector<int> v(f.begin(), f.end());
      vector<int> primes;
      for (int i: v) {
         bool isprime = true;
         for (int j: primes) {
            if (i % j == 0) isprime = false;
         }
         if (isprime) primes.push_back(i);
      }

      map<int, bool> used;
      vector<int> ans;
      ans.push_back(n);
      used[n] = true;
      for (int i = 0; i + 1 < sz(primes); ++i) {
         used[primes[i] * primes[i + 1]] = true;
      }
      for (int idx = 0; idx < sz(primes); ++idx) {
         int p = primes[idx];
         for (int i: v) {
            if (used[i]) continue;
            if (i % p == 0) {
               ans.push_back(i);
               used[i] = true;
            }
         }

         if (idx + 1 < sz(primes)) {
            int q = primes[idx + 1];
            if (p * q != n) {
               ans.push_back(p * q);
            }
         }
      }

      int anscnt = 0;
      int prv = ans.back();
      for (int i: ans) {
         cout << i << " ";
         if (__gcd(prv, i) == 1) ++anscnt;
         prv = i;
      }
      cout << "\n";
      cout << anscnt << "\n";
   }
}