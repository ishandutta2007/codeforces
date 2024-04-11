#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200100;
int N, K, S, T;

int ar[MAXN];
pii cars[MAXN];

bool canDo(int capacity) {
  int timeLeft = T;
  for (int i = 0; i + 1 < K; ++i) {
    int distance = ar[i + 1] - ar[i];
    if (distance > capacity) return false;
    int accel = capacity - distance;
    if (accel > distance) accel = distance;
    int time = distance * 2 - accel;
    timeLeft -= time;
    if (timeLeft < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d %d %d %d", &N, &K, &S, &T);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d", &(cars[i].second), &(cars[i].first));
  }
  for(int i = 0; i < K; ++i) {
    scanf("%d", ar + i);
  }
  ar[K++] = S;
  ar[K++] = 0;
  sort(ar, ar + K);

  sort(cars, cars + N);
  for(int i = N - 2; i >= 0; --i) {
    if (cars[i + 1].second < cars[i].second) {
      cars[i].second = cars[i + 1].second;
    }
  }

  int lo = 0;
  int hi = N;

  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (canDo(cars[mid].first)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  if (lo == N) {
    printf("-1\n");
  } else {
    printf("%d\n", cars[lo].second);
  }
}