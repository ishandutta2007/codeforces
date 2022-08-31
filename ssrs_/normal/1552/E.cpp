#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> c(n * k);
  for (int i = 0; i < n * k; i++){
    cin >> c[i];
    c[i]--;
  }
  vector<int> s(n, 0);
  int c1 = 0, c2 = 0;
  vector<int> a(n), b(n);
  for (int i = 0; i < n * k; i++){
    if (s[c[i]] == 0){
      s[c[i]] = 1;
      a[c[i]] = i;
      c1++;
    } else if (s[c[i]] == 1){
      s[c[i]] = 2;
      b[c[i]] = i;
      c1--;
      c2++;
    }
    if (c2 == (n + k - 2) / (k - 1)){
      for (int j = 0; j < n; j++){
        if (s[j] == 1){
          s[j] = 0;
        }
      }
      c1 = 0;
      c2 = 0;
    }
  }
  for (int i = 0; i < n; i++){
    cout << a[i] + 1 << ' ' << b[i] + 1 << endl;
  }
}