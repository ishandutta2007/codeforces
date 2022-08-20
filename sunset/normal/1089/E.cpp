#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  n -= 2;
  vector<int> a(N);
  a[0] = 1;
  a[N - 1] = 2;
  while (n) {
    for (int i = 0; i < N; ++i) {
      if (a[i] < N) {
        ++a[i];
        break;
      }
    }
    --n;
  }
  int column = 0;
  vector<pair<int, int>> answer;
  for (int i = 0; i < N; ++i) {
    if (a[i]) {
      answer.emplace_back(i, column);
      --a[i];
      if (a[i] == N - 1) {
        if (i == N - 1) {
          for (int j = 0; j < N; ++j) {
            if (j != column) {
              answer.emplace_back(i, j);
            }
          }
        } else {
          for (int j = N - 1; ~j; --j) {
            if (j != column) {
              answer.emplace_back(i, j);
            }
          }
          column = !column;
        }
      } else {
        if (i == N - 1) {
          for (int j = 0; j < N && a[i] > 1; ++j) {
            if (j != column) {
              answer.emplace_back(i, j);
              --a[i];
            }
          }
          answer.emplace_back(i, N - 1);
        } else {
          for (int j = 0; j < N && a[i]; ++j) {
            if (j != column) {
              answer.emplace_back(i, j);
              --a[i];
              if (!a[i]) {
                column = j;
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < answer.size(); ++i) {
    printf("%c%d%c", answer[i].first + 'a', answer[i].second + 1, i == answer.size() - 1 ? '\n' : ' ');
  }
  return 0;
}