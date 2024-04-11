#include <bits/stdc++.h>
using namespace std;
long long INF = 2000000000;
long long INF2 = 1000000000000000000;
long long cost(int x, vector<int> h, int A, int R, int M){
  int N = h.size();
  long long add = 0;
  long long remove = 0;
  for (int i = 0; i < N; i++){
    if (h[i] < x){
      add += x - h[i];
    }
    if (h[i] > x){
      remove += h[i] - x;
    }
  }
  long long move = min(add, remove);
  add -= move;
  remove -= move;
  long long cost = add * A + remove * R + move * M;
  return cost;
}
int main(){
  int N, A, R, M;
  cin >> N >> A >> R >> M;
  M = min(M, A + R);
  vector<int> h(N);
  for (int i = 0; i < N; i++){
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  long long l = -1;
  long long r = INF;
  for (int i = 0; i < 100; i++){
    long long mv1 = (l * 2 + r) / 3;
    long long mv2 = (l + r * 2) / 3;
    long long res1 = cost(mv1, h, A, R, M);
    long long res2 = cost(mv2, h, A, R, M);
    if (res1 > res2){
      l = mv1;
    } else {
      r = mv2;
    }
  }
  long long ans = INF2;
  for (int i = l; i <= r; i++){
    ans = min(ans, cost(i, h, A, R, M));
  }
  cout << ans << endl;
}