#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 300100;

int N;
int K;

pii ar[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    int tmp;
    scanf("%d", &tmp);
    ar[i] = pii(tmp, i + 1);
  }
  cin >> K;
  sort(ar, ar + N);

  ll sum = 0;
  ll cur = 0;
  for(int i = 0; i < K; ++i) {
    cur += ll(i) * ar[i].first - sum;
    sum += ar[i].first;
  }

  ll ans = cur;
  int bst = -1;
  for(int i = 0; i + K < N; ++i) {
    cur += ll(K - 1) * ar[i + K].first;
    cur += ll(K - 1) * ar[i].first;
    sum -= ar[i].first;
    cur -= 2 * sum;
    sum += ar[i + K].first;

    if (cur < ans) ans = cur, bst = i;
  }

  for(int i = bst + 1; i <= bst + K; ++i) {
    printf("%d ", ar[i].second);
  }
  printf("\n");
  return 0;
}