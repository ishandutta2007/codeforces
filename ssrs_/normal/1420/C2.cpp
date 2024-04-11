#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
struct segment_tree{
  int N;
  vector<long long> A, B, C, D;
  void calc(int i){
    int l = i * 2 + 1, r = i * 2 + 2;
    A[i] = max(A[l] + A[r], B[l] + D[r]);
    B[i] = max(A[l] + B[r], B[l] + C[r]);
    C[i] = max(C[l] + C[r], D[l] + B[r]);
    D[i] = max(C[l] + D[r], D[l] + A[r]);
  }
  segment_tree(vector<int> &a){
    int n = a.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    A = vector<long long>(N * 2 - 1, 0);
    B = vector<long long>(N * 2 - 1, -INF);
    C = vector<long long>(N * 2 - 1, 0);
    D = vector<long long>(N * 2 - 1, -INF);
    for (int i = 0; i < n; i++){
      B[N - 1 + i] = a[i];
      D[N - 1 + i] = - a[i];
    }
    for (int i = N - 2; i >= 0; i--){
      calc(i);
    }
  }
  void update(int i, int x){
    i += N - 1;
    B[i] = x;
    D[i] = - x;
    while (i > 0){
      i = (i - 1) / 2;
      calc(i);
    }
  }
  long long get(){
    return max(A[0], B[0]);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    segment_tree ST(a);
    cout << ST.get() << endl;
    for (int j = 0; j < q; j++){
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      swap(a[l], a[r]);
      ST.update(l, a[l]);
      ST.update(r, a[r]);
      cout << ST.get() << endl;
    }
  }
}