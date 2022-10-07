#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1001000;

typedef long long ll;

char str[MAXN];
int lft[MAXN];
int rgt[MAXN];

int N;

bool dig(char c) {
  return c >= '0' && c <= '9';
}

bool let(char c) {
  return c >= 'a' && c <= 'z';
}

int main() {
  scanf("%s", str);
  while (str[N]) ++N;
  for(int i = 0; i < N; ++i) {
    if (let(str[i])) lft[i + 1] = lft[i] + 1;
    else if (dig(str[i])) lft[i + 1] = lft[i];
    else if (str[i] == '_') lft[i + 1] = lft[i];
    else lft[i + 1] = 0;
  }
  for(int i = N - 1; i >= 0; --i) {
    if (let(str[i])) rgt[i] = rgt[i + 1] + 1;
    else rgt[i] = 0;
  }

  ll ans = 0;
  int prv = 0;
  for(int i = 0; i < N; ++i) {
    if (str[i] == '.') {
      if (i > 1 && str[i - 1] != '@')
        ans += ll(prv) * rgt[i + 1];
    }

    if (!let(str[i]) && !dig(str[i])) prv = 0;
    if (str[i] == '@') {
      prv = lft[i];
    }
  }

  cout << ans << "\n";
  return 0;
}