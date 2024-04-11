#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    long long sum1 = 0;
    long long max1 = 0;
    for (int j = 0; j < n - 1; j++){
      sum1 = max(sum1 + a[j], (long long) 0);
      max1 = max(max1, sum1);
    }
    long long sum2 = 0;
    long long max2 = 0;
    for (int j = 1; j < n; j++){
      sum2 = max(sum2 + a[j], (long long) 0);
      max2 = max(max2, sum2);
    }
    if (sum > max1 && sum > max2){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}