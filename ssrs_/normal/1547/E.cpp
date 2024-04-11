#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int j = 0; j < k; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> t(k);
    for (int j = 0; j < k; j++){
      cin >> t[j];
    }
    vector<int> t2(n, INF);
    for (int j = 0; j < k; j++){
      t2[a[j]] = t[j];
    }
    vector<int> L(n + 1, INF);
    for (int j = 0; j < n; j++){
      L[j + 1] = min(L[j], t2[j] - j);
    }
    vector<int> R(n + 1, INF);
    for (int j = n - 1; j >= 0; j--){
      R[j] = min(R[j + 1], t2[j] + j);
    }
    for (int j = 0; j < n; j++){
      cout << min(L[j + 1] + j, R[j] - j);
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}