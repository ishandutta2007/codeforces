#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int N, M;

int main() {
  scanf("%d %d", &N, &M);
  ll sum = 0;
  int cur = 1;
  for(int i = 0; i < M;++i) {
    int x;
    scanf("%d", &x);
    int dist = x - cur;
    if (dist < 0) dist += N;
    sum += dist;
    cur = x;
  }

  cout << sum << "\n";
}