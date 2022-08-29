#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = 0;
    for (int j = 1; j <= n; j++){
      cin >> a[j];
    }
    vector<int> Sneg(n + 3);
    Sneg[0] = 0;
    vector<int> Stwo(n + 3);
    Stwo[0] = 0;
    for (int j = 0; j < n + 2; j++){
      Sneg[j + 1] = Sneg[j];
      Stwo[j + 1] = Stwo[j];
      if (a[j] < 0){
        Sneg[j + 1]++;
      }
      if (abs(a[j]) == 2){
        Stwo[j + 1]++;
      }
    }
    vector<int> p;
    for (int j = 0; j < n + 2; j++){
      if (a[j] == 0){
        p.push_back(j);
      }
    }
    int m = p.size();
    int mx = 0;
    int x = 0, y = n;
    for (int j = 0; j < m - 1; j++){
      int L = p[j] + 1, R = p[j + 1];
      if ((Sneg[R] - Sneg[L]) % 2 == 0){
        int cnt = Stwo[R] - Stwo[L];
        if (cnt > mx){
          mx = cnt;
          x = L - 1;
          y = n + 1 - R;
        }
      } else {
        vector<int> neg;
        for (int k = L; k < R; k++){
          if (a[k] < 0){
            neg.push_back(k);
          }
        }
        int L1 = neg[0] + 1, R1 = R;
        int cnt1 = Stwo[R1] - Stwo[L1];
        if (cnt1 > mx){
          mx = cnt1;
          x = L1 - 1;
          y = n + 1 - R1;
        }
        int L2 = L, R2 = neg[neg.size() - 1];
        int cnt2 = Stwo[R2] - Stwo[L2];
        if (cnt2 > mx){
          mx = cnt2;
          x = L2 - 1;
          y = n + 1 - R2;
        }
      }
    }
    cout << x << ' ' << y << endl;
  }
}