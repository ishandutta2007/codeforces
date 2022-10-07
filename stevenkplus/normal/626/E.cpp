#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 200100;

ll ar[MAXN];
ll prefs[MAXN];
int N;

int x(int a, int b, int j) {
  return a - j;
}

int y(int a, int b, int j) {
  return N - j;
}

ll sm(int a, int b, int j) {
  ll ret = ar[a];
  if (a != b) {
    ret += ar[b];
  }
  ret += prefs[N] - prefs[y(a, b, j)];
  ret += prefs[a] - prefs[x(a, b, j)];
  return ret;
}

int ct(int a, int b, int j) {
  int ret = 2 * j;
  if (a == b) ret += 1;
  else ret += 2;
  return ret;
}

ll nt(int a, int b, int j) {
  return ar[x(a, b, j)] + ar[y(a, b, j)];
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    cin >> ar[i];
  }
  sort(ar, ar + N);
  for(int i = 0; i < N; ++i) {
    prefs[i + 1] = prefs[i] + ar[i];
  }

  int ansi;
  ll bsum = -1;
  int bcnt = 1;
  for(int i = 0; i < 2 * N - 1; ++i) {
    int a = i / 2, b = (i + 1) / 2;
    int lo = 0;
    int hi = N;
    while (lo < hi) {
      int j = (lo + hi + 1) / 2;
      if (x(a, b, j) >= 0 && y(a, b, j) > b && nt(a, b, j) * ct(a, b, j) > sm(a, b, j) * 2) {
        lo = j;
      } else {
        hi = j - 1;
      }
    }

    ll sum = sm(a, b, lo);
    int cnt = ct(a, b, lo);
//    printf("x = %d\n", x(a, b, lo));
    // if (sum / cnt - med > bsum bcnt * bmed / bcnt - bmed)
    sum -= cnt * (ar[a] + ar[b]) / 2;
    if (sum * bcnt > bsum * cnt) {
      bsum = sum;
      bcnt = cnt;
      ansi = i;
    }
  }

  printf("%d\n", bcnt);
  {
    int i = ansi;
    int a = i / 2, b = (i + 1) / 2;
    ll sum = ar[a];
    int cnt = 1;
    cout << ar[a] << " ";
    if (a != b) {
      sum += ar[b];
      ++cnt;
      cout << ar[b] << " ";
    }

    for(int j = 0; N - 1 - j > b && a - 1 - j >= 0; ++j) {
      ll nxt = ar[N - 1 - j] + ar[a - 1 - j];
      if (nxt * cnt > sum * 2) {
        sum += nxt;
        cnt += 2;
        cout << ar[N - 1 - j] << " " << ar[a - 1 - j] << " ";
      } else {
        break;
      }
    }
    printf("\n");
  }

  return 0;
}