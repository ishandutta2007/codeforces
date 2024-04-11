#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;

char s[100005];
int cnt[26];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  ll val;
  scanf("%d%lld%s", &n, &val, s);
  ll sum = 0;
  sum += 1 << (s[n - 1] - 'a');
  sum -= 1 << (s[n - 2] - 'a');
  for (int i = 0; i < n - 2; ++i)
    sum += 1 << (s[i] - 'a'), cnt[s[i] - 'a']++;
  val -= sum;
  if (val > 0 || (val & 1)) return puts("No"), 0;
  val = -val; val >>= 1;
  for (int i = 25; i >= 0; --i) {
    ll de = min((ll)cnt[i], val >> i);
    val -= (de << i);
  }
  puts(val == 0 ? "Yes" : "No");
  return 0;
}