#include <cstdio>
#include <iostream>
using namespace std;

const int inf = 100;
const int MAXN = 50;
int X[MAXN];
int Y[MAXN];

int n;

bool go(int out) {
  int mx = inf, my = inf;
  int Mx = 0, My = 0;
  for(int i = 0; i < n; ++i) {
    if (i == out) continue;
    mx = min(mx, X[i]);
    Mx = max(Mx, X[i]);
    my = min(my, Y[i]);
    My = max(My, Y[i]);
  }
  for(int i = 0; i < n; ++i) {
    if (i == out) continue;
    if (X[i] != mx && X[i] != Mx && Y[i] != my && Y[i] != My) return false;
  }
  if (Mx - mx != My - my) return false;
  return true;
}


int main() {
  cin >> n;
  n = 4 * n + 1;
  for(int i = 0; i < n; ++i) {
    cin >> X[i] >> Y[i];
  }
  for(int i = 0; i < n; ++i) {
    if (go(i)) {
      cout << X[i] << " " << Y[i] << "\n";
    }
  }
}