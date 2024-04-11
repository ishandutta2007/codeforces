#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 300100;

map<int, int> conn[MAXN];

int A[MAXN];
int B[MAXN];
int cnt[MAXN];

int N, P;

int BIT[MAXN];

void inc(int x) {
  while (x < MAXN) {
    ++BIT[x];
    x += x & -x;
  }
}

int ask(int x) {
  if (x < 0) return 0;
  int ans = 0;
  while (x) {
    ans += BIT[x];
    x -= x & -x;
  }
  return ans;
}

int main() {
  scanf("%d %d", &N, &P);
  for(int i = 0; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    A[i] = a;
    B[i] = b;
    ++conn[a][b];
    ++conn[b][a];
    ++cnt[a];
    ++cnt[b];
  }

  long long ans = 0;
  for(int i = 1; i <= N; ++i) {
    int get = i - 1 - ask(P - cnt[i]);
    ans += get;
    repi(j, conn[i]) {
      int oth = j->first;
      if (oth < i) {
        if (cnt[oth] + cnt[i] >= P && cnt[oth] + cnt[i] - j->second < P) {
          --ans;
        }
      }
    }
    inc(cnt[i] + 1);
  }

  cout << ans << "\n";
  return 0;
}