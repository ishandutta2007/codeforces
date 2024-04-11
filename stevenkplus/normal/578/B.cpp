#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 200100;

ll pref[MAXN];
ll suff[MAXN];
ll ar[MAXN];
int N, K, X;

int main() {
  scanf("%d %d %d", &N, &K, &X);
  ll mult = 1;
  for(int i = 0; i < K; ++i) {
    mult *= X;
  }

  for(int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    ar[i] = x;
  }

  for(int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] | ar[i];
  }

  for(int i = N - 1; i >= 0; --i) {
    suff[i] = suff[i + 1] | ar[i];
  }

  ll ans = suff[0];
  for(int i = 0; i < N; ++i) {
    ll cur = ar[i] * mult;
    ll val = pref[i] | cur | suff[i + 1];
    if (val > ans) ans = val;
  }

  cout << ans << "\n";
}