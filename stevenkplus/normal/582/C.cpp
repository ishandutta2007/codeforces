#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 200100;
int ar[MAXN];
int maxC[MAXN];

int gcd[MAXN];

int N;

int tot[MAXN]; // tot[x]: #y <= x s.t. gcd(y, N == k)
ll check(int k) {
  tot[1] = 0;
  for(int i = 1; i < N; ++i) {
    if (gcd[i] == k) {
      ++tot[i];
    }
    tot[i + 1] = tot[i];
  }

  for(int i = 0; i < k; ++i) {
    maxC[i] = 0;
  }
  for(int i = 0; i < N; ++i) {
    if (ar[i] > maxC[i % k]) {
      maxC[i % k] = ar[i];
    }
  }

  int run = 0;
  for(int i = 0; i < N; ++i) {
    if (ar[i] == maxC[i % k]) {
      ++run;
    } else {
      run = 0;
    }
  }

  ll ans = 0;
  for(int i = 0; i < N; ++i) {
    if (ar[i] == maxC[i % k]) {
      ++run;
    } else {
      run = 0;
    }

    if (run > N) run = N;
    ans += tot[run];
  }
  return ans;
}

int _gcd(int a, int b) {
  if (a == 0) return b;
  return _gcd(b % a, a);
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 1; i <= N; ++i) {
    gcd[i] = _gcd(i, N);
  }

  ll ans = 0;
  for(int i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      ll c = check(i);
      ans += c;
//      printf("check %d: %d\n", i, c);
      if (i != N / i) {
        ll c = check(N / i);
//      printf("check %d: %d\n", N / i, c);
        ans += c;
      }
    }
  }

  cout << ans << "\n";
}