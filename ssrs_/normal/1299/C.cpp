#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  vector<pair<int, long long>> L(n);
  for (int i = 0; i < n; i++){
    L[i] = make_pair(-(i + 1), S[i + 1]);
  }
  vector<pair<int, long long>> L2;
  vector<int> id;
  L2.push_back(make_pair(0, 0));
  id.push_back(-1);
  L2.push_back(L[0]);
  id.push_back(0);
  for (int i = 1; i < n; i++){
    while (1){
      int a1 = L2[L2.size() - 2].first;
      int a2 = L2[L2.size() - 1].first;
      int a3 = L[i].first;
      long long b1 = L2[L2.size() - 2].second;
      long long b2 = L2[L2.size() - 1].second;
      long long b3 = L[i].second;
      if ((a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2)){
        L2.pop_back();
        id.pop_back();
        if (L2.size() < 2){
          break;
        }
      } else {
        break;
      }
    }
    L2.push_back(L[i]);
    id.push_back(i);
  }
  vector<double> b(n);
  double avg0 = - (double) L2[1].second / L2[1].first;
  for (int i = 0; i <= id[1]; i++){
    b[i] = avg0;
  }
  int m = L2.size();
  for (int i = 1; i < m - 1; i++){
    int a1 = L2[i].first;
    int a2 = L2[i + 1].first;
    long long b1 = L2[i].second;
    long long b2 = L2[i + 1].second;
    double avg = (double) (b1 - b2) / (a2 - a1);
    for (int j = id[i] + 1; j <= id[i + 1]; j++){
      b[j] = avg;
    }
  }
  for (int i = 0; i < n; i++){
    cout << b[i] << "\n";
  }
}