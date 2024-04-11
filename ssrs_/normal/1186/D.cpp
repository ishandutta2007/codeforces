#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> p(n, 0);
  vector<bool> ok(n);
  for (int i = 0; i < n; i++){
    int l = a[i].size();
    int neg = 0;
    if (a[i][0] == '-'){
      neg = 1;
    }
    for (int j = neg; j < n; j++){
      if (a[i][j] != '.'){
        p[i] *= 10;
        p[i] += a[i][j] - '0';        
      } else {
        break;
      }
    }
    if (neg){
      p[i] *= -1;
      p[i]--;
    }
    string s = a[i].substr(a[i].size() - 5);
    if (s == "00000"){
      ok[i] = false;
      if (p[i] < 0){
        p[i]++;
      }
    } else {
      ok[i] = true;
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += p[i];
  }
  vector<int> b = p;
  for (int i = 0; i < n; i++){
    if (sum < 0 && ok[i]){
      b[i]++;
      sum++;
    }
  }
  for (int i = 0; i < n; i++){
    cout << b[i] << endl;
  }
}