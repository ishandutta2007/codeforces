#include <cstdio>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 300100;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<pdi, pii> str;
int A[MAXN];
int B[MAXN];
int state[MAXN];

int N, W;
int get1(int x) {
  if (state[x] == 0) return A[x];
  else if (state[x] == 1) return B[x];
  else return -1;
}

priority_queue<str, vector<str>, greater<str> > pq;

int main() {
  scanf("%d %d", &N, &W);
  for(int i = 0; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    b -= a;
    A[i] = a;
    B[i] = b;
    pq.push(str(pdi(a, a), pii(i, 1)));
    pq.push(str(pdi((a + b) / 2., a + b), pii(i, 2)));
  }

  int took = 0;
  ll sum = 0;
  while (took < W) {
    str top = pq.top();
    int cur = top.second.first;
    int type = top.second.second;
    int cost = top.first.second;
//    printf("%d, %d\n", cur, type);
    pq.pop();
    if (type == 2 && state[cur] != 0) continue;
    if (type == 1 && get1(cur) != cost) continue;
    if (type == 2 && took + 1 == W) continue;

//    printf("taking %d %d for %d\n", cur, type, cost);
    ++took;
    sum += get1(cur);
    ++state[cur];
    if (state[cur] == 1) {
      pq.push(str(pdi(B[cur], B[cur]), pii(cur, 1)));
    }
  }

  int a = -1, b = -1;
  int va = -1, vb = -1;
  for(int i = 0; i < N; ++i) {
    if (state[i] == 0) continue;
    int val = A[i];
    if (state[i] == 2) val = B[i];
    if (a == -1 || val >= va) {
      b = a;
      a = i;
      vb = va;
      va = val;
    } else if (val > vb) {
      vb = val;
      b = i;
    }
  }


  int m2 = -1;
  for(int i = 0; i < N; ++i) {
    if (state[i] == 0 || (state[i] == 1 && (i == a || i == b))) {
      if (m2 == -1 || A[i] + B[i] < A[m2] + B[m2]) {
        m2 = i;
      }
    }
  }

  if (a > -1 && b > -1 && m2 > -1 && va + vb > A[m2] + B[m2]) {
    sum -= (va + vb);
    sum += A[m2] + B[m2];
    --state[a];
    --state[b];
    state[m2] += 2;
  }

  cout << sum << "\n";
  for(int i = 0; i < N; ++i) {
    printf("%d", state[i]);
  }
  printf("\n");
  return 0;
}