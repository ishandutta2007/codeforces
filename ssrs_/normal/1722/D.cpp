#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >>t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long sum = 0;
    vector<int> add;
    for (int j = 0; j < n; j++){
      if (s[j] == 'L'){
        sum += j;
        add.push_back(n - 1 - j * 2);
      }
      if (s[j] == 'R'){
        sum += n - 1 - j;
        add.push_back(j * 2 - n + 1);
      }
    }
    sort(add.begin(), add.end(), greater<int>());
    for (int j = 0; j < n; j++){
      sum += max(add[j], 0);
      cout << sum;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}