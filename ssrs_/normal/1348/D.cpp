#include <bits/stdc++.h>
using namespace std;
string bit(int n){
  string ans;
  while (n > 0){
    ans += (n % 2) + '0';
    n /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    string S = bit(n);
    int ans = S.size() - 1;
    cout << S.size() - 1 << endl;
    vector<long long> count(ans + 1);
    long long sum = 0;
    for (int j = 0; j <= ans; j++){
      if (j < ans){
        count[j] = ((long long) 1 << j);
        sum += count[j];
      } else {
        count[j] = n - sum;
      }
    }
    if (count[ans - 1] > count[ans]){
      long long tmp = count[ans - 1] + count[ans];
      count[ans - 1] = tmp / 2;
      count[ans] = tmp / 2;
      if (tmp % 2 == 1){
        count[ans]++;
      }
    }
    for (int j = 0; j < ans; j++){
      cout << count[j + 1] - count[j];
      if (j < ans - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}