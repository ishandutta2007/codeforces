#include <bits/stdc++.h>
long long INF = 1000000000000000000;
using namespace std;
vector<int> list_pf(int x){
  vector<int> ans;
  for (int i = 2; i * i <= x; i++){
    if (x % i == 0){
      ans.push_back(i);
      while (x % i == 0){
        x /= i;
      }
    }
  }
  if (x != 1){
    ans.push_back(x);
  }
  return ans;
}
void set_union(set<int> &st, vector<int> vec){
  for (int x : vec){
    st.insert(x);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long A, B;
  cin >> N >> A >> B;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  set<int> st;
  set_union(st, list_pf(a[0] - 1));
  set_union(st, list_pf(a[0]));
  set_union(st, list_pf(a[0] + 1));
  set_union(st, list_pf(a[N - 1] - 1));
  set_union(st, list_pf(a[N - 1]));
  set_union(st, list_pf(a[N - 1] + 1));
  long long ans = INF;
  for (int x : st){
    vector<long long> L(N + 1);
    L[0] = A * N;
    for (int i = 0; i < N; i++){
      if (L[i] == INF){
        L[i + 1] = INF;
      } else if ((a[i] - 1) % x != 0 && a[i] % x != 0 && (a[i] + 1) % x != 0){
        L[i + 1] = INF;
      } else {
        if (a[i] % x != 0){
          L[i + 1] = L[i] + B - A;
        } else {
          L[i + 1] = L[i] - A;
        }
      }
    }
    vector<long long> R(N + 1);
    R[N] = 0;
    for (int i = N - 1; i >= 0; i--){
      if (R[i + 1] == INF){
        R[i] = INF;
      } else if ((a[i] - 1) % x != 0 && a[i] % x != 0 && (a[i] + 1) % x != 0){
        R[i] = INF;
      } else {
        if (a[i] % x != 0){
          R[i] = R[i + 1] + B - A;
        } else {
          R[i] = R[i + 1] - A;
        }
      }
    }
    /*
    cout << "x = " << x << endl;
    for (int i = 0; i <= N; i++){
      cout << L[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i <= N; i++){
      cout << R[i] << ' ';
    }
    cout << endl;
    */
    for (int i = 0; i < N - 1; i++){
      L[i + 1] = min(L[i + 1], L[i]);
    }
    for (int i = N - 1; i >= 1; i--){
      R[i] = min(R[i], R[i + 1]);
    }
    for (int i = 0; i <= N; i++){
      ans = min(ans, L[i] + R[i]);
    }
  }
  cout << ans << endl;
}