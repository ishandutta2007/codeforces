#include <bits/stdc++.h>
using namespace std;
istream& operator >>(istream &is, __int128_t &a){
  a = 0;
  string s;
  is >> s;
  for (char c : s){
    a = a * 10 + c - '0';
  }
  return is;
}
ostream& operator <<(ostream &os, __int128 a){
  string s;
  while (a > 0){
    s += (char) ('0' + a % 10);
    a /= 10;
  }
  if (s.empty()){
    s = "0";
  }
  reverse(s.begin(), s.end());
  os << s;
  return os;
}
__int128_t gcd(__int128_t a, __int128_t b){
  if (b == 0){
    return a;
  } else {
    return gcd(b, a % b);
  }
}
__int128_t lcm(__int128_t a, __int128_t b){
  return a / gcd(a, b) * b;
}
struct segment_tree{
  int N;
  vector<__int128_t> ST;
  segment_tree(){
  }
  segment_tree(vector<__int128_t> A){
    int N2 = A.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    ST = vector<__int128_t>(N * 2 - 1, 1);
    for (int i = 0; i < N2; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = lcm(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void update(int i, __int128_t x){
    i += N - 1;
    ST[i] = x;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = lcm(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  __int128_t all(){
    return ST[0];
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<__int128_t> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<__int128_t> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    vector<vector<__int128_t>> g(n, vector<__int128_t>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        g[j][k] = gcd(a[j], b[k]);
      }
    }
    vector<segment_tree> ST1(n), ST2(m);
    for (int j = 0; j < n; j++){
      vector<__int128_t> tmp(m);
      for (int k = 0; k < m; k++){
        tmp[k] = g[j][k];
      }
      ST1[j] = segment_tree(tmp);
    }
    for (int j = 0; j < m; j++){
      vector<__int128_t> tmp(n);
      for (int k = 0; k < n; k++){
        tmp[k] = g[k][j];
      }
      ST2[j] = segment_tree(tmp);
    }
    vector<bool> used1(n, true), used2(m, true);
    while (true){
      bool ok = false;
      for (int j = 0; j < n; j++){
        if (used1[j]){
          if (ST1[j].all() != a[j]){
            used1[j] = false;
            for (int k = 0; k < m; k++){
              ST2[k].update(j, 1);
            }
            ok = true;
          }
        }
      }
      for (int j = 0; j < m; j++){
        if (used2[j]){
          if (ST2[j].all() != b[j]){
            used2[j] = false;
            for (int k = 0; k < n; k++){
              ST1[k].update(j, 1);
            }
            ok = true;
          }
        }
      }
      if (!ok){
        break;
      }
    }
    vector<__int128_t> sa;
    for (int j = 0; j < n; j++){
      if (used1[j]){
        sa.push_back(a[j]);
      }
    }
    vector<__int128_t> sb;
    for (int j = 0; j < m; j++){
      if (used2[j]){
        sb.push_back(b[j]);
      }
    }
    if (sa.empty() || sb.empty()){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int ca = sa.size();
      int cb = sb.size();
      cout << ca << ' ' << cb << endl;
      for (int j = 0; j < ca; j++){
        cout << sa[j];
        if (j < ca - 1){
          cout << ' ';
        }
      }
      cout << endl;
      for (int j = 0; j < cb; j++){
        cout << sb[j];
        if (j < cb - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}