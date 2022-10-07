#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

long long A[MAXN], // A[level] = rightshift of values
          B[MAXN]; // B[level] = rightshift of nodes

int lvl(long long val) {
  // count digits in val
  int res = 0;
  while (val) {
    ++res;
    val /= 2;
  }
  return res;
}

long long rotate(int level, long long value, long long shiftBy) {
  long long mod = 1LL << (level - 1);
  return mod | ((value + shiftBy) & (mod - 1));
  // don't need to worry about overflow (signed)
}

long long X, K;
void Q1() {
  cin >> X >> K;
  int i = lvl(X);
  A[i] += K;

}

void Q2() {
  cin >> X >> K;
  int i = lvl(X);
  B[i] += K;
}

void Q3() {
  cin >> X;
  // cerr << "on Q3 " << X << "\n";
  vector<long long> path;
  int i = lvl(X);
  long long cur = rotate(i, X, A[i]);
  while (i > 0) {
    // cerr << "on i= " << i << " cur=" << cur << "\n";
    path.push_back(rotate(i, cur, -A[i]));
    cur = rotate(i, cur, B[i]);
    cur /= 2;
    i--;
  }
  for(int j = 0; j < path.size(); ++j) {
    printf("%I64d ", path[j]);
  }
  printf("\n");
}

int Q, type;
int main() {
  cin >> Q;
  for (int q = 0; q < Q; ++q) {
    cin >> type;
    if (type == 1) Q1();
    else if (type == 2) Q2();
    else if (type == 3) Q3();
  }
}