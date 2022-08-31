#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<double> M(n);
  for (int i = 0; i < n; i++){
    cin >> M[i];
  }
  vector<double> m(n);
  for (int i = 0; i < n; i++){
    cin >> m[i];
  }
  for (int i = 1; i < n; i++){
    M[i] += M[i - 1];
  }
  for (int i = n - 2; i >= 0; i--){
    m[i] += m[i + 1];
  }
  vector<double> S(n + 1), T(n + 1);
  S[0] = 0;
  T[0] = 0;
  S[n] = 1;
  T[n] = 1;
  for (int i = 1; i < n; i++){
    double prod = M[i - 1];
    double sum = 1 + M[i - 1] - m[i];
    double D = sum * sum - 4 * prod;
    S[i] = (sum + sqrt(D)) / 2;
    T[i] = (sum - sqrt(D)) / 2;
  }
  for (int i = 0; i < n; i++){
    cout << S[i + 1] - S[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
  for (int i = 0; i < n; i++){
    cout << T[i + 1] - T[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;  
}