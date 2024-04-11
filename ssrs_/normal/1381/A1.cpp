#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    vector<int> p;
    for (int j = 1; j < n; j++){
      if (a[j] != a[j - 1]){
        p.push_back(j - 1);
      }
    }
    if (a[n - 1] != b[n - 1]){
      p.push_back(n - 1);
    }
    vector<int> p2;
    for (int j = 1; j < n; j++){
      if (b[j] != b[j - 1]){
        p2.push_back(j - 1);
      }
    }
    while (!p2.empty()){
      int tmp = p2.back();
      p.push_back(tmp);
      p2.pop_back();
    }
    int k = p.size();
    cout << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << p[j] + 1;
    }
    cout << endl;
  }
}