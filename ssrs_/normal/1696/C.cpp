#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long>> solve(vector<int> A, int M){
  int N = A.size();
  vector<pair<int, long long>> ans;
  for (int i = 0; i < N; i++){
    int X = 1;
    while (A[i] % M == 0){
      A[i] /= M;
      X *= M;
    }
    if (i == 0){
      ans.push_back(make_pair(A[i], X));
    } else if (A[i] == ans.back().first){
      ans.back().second += X;
    } else {
      ans.push_back(make_pair(A[i], X));
    }
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int j = 0; j < k; j++){
      cin >> b[j];
    }
    vector<pair<int, long long>> P1 = solve(a, m);
    vector<pair<int, long long>> P2 = solve(b, m);
    if (P1 == P2){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}