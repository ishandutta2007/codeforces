#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 500100;

bool done[MAXN];
bool inq[MAXN];
int A[MAXN];
int B[MAXN];
int ar[MAXN];
int N;

bool check(int x) {
  if (inq[x]) return false;
  if (done[x]) return false;
  if (A[x] && B[x]) {
    if (ar[A[x]] >= ar[x] && ar[B[x]] >= ar[x]) {
      return true;
    }
  }
  return false;
}

queue<int> q;

void upd(int x) {
  if (check(x)) {
    inq[x] = true;
    q.push(x);
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 1; i <= N; ++i) {
    A[i] = i + 1;
    B[i] = i - 1;
    upd(i);
  }

  A[0] = 1;
  ll ans = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    inq[x] = false;
    if (check(x)) {
      //printf("erasing %d: %d\n", x, ar[x]);
      A[B[x]] = A[x];
      B[A[x]] = B[x];
      ans += min(ar[A[x]], ar[B[x]]);
      upd(A[x]);
      upd(B[x]);
    }
  }

  // merge step
  int mid = A[0];
  while (A[mid] <= N && ar[mid] < ar[A[mid]]) {
    mid = A[mid];
  }

  while (A[mid] && B[mid]) {
    if (min(ar[A[mid]], ar[B[mid]]) >= max(ar[A[A[mid]]], ar[B[B[mid]]])) {} else { break; }
    ans += min(ar[A[mid]], ar[B[mid]]);
    //printf("erasing %d: %d\n", mid, ar[mid]);
    A[B[mid]] = A[mid];
    B[A[mid]] = B[mid];
    if (ar[A[mid]] > ar[B[mid]]) mid = A[mid];
    else mid = B[mid];
  }
  for(int x = A[mid]; x; x = A[x]) {
    //printf("adding %d\n", ar[A[x]]);
    ans += ar[A[x]];
  }
  for(int x = B[mid]; x; x = B[x]) {
    //printf("adding %d\n", ar[B[x]]);
    ans += ar[B[x]];
  }
  ans += min(ar[A[mid]], ar[B[mid]]);

  cout << ans << "\n";
  return 0;
}