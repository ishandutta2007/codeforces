#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<int> a1(n1);
  for (int i = 0; i < n1; i++){
    cin >> a1[i];
  }
  vector<int> a2(n2);
  for (int i = 0; i < n2; i++){
    cin >> a2[i];
  }
  vector<int> a3(n3);
  for (int i = 0; i < n3; i++){
    cin >> a3[i];
  }
  int mn1 = INF;
  for (int i = 0; i < n1; i++){
    mn1 = min(mn1, a1[i]);
  }
  int mn2 = INF;
  for (int i = 0; i < n2; i++){
    mn2 = min(mn2, a2[i]);
  }
  int mn3 = INF;
  for (int i = 0; i < n3; i++){
    mn3 = min(mn3, a3[i]);
  }
  long long sum1 = 0;
  for (int i = 0; i < n1; i++){
    sum1 += a1[i];
  }
  long long sum2 = 0;
  for (int i = 0; i < n2; i++){
    sum2 += a2[i];
  }
  long long sum3 = 0;
  for (int i = 0; i < n3; i++){
    sum3 += a3[i];
  }
  long long sum = sum1 + sum2 + sum3;
  cout << sum - min({sum1, sum2, sum3, (long long) (mn1 + mn2), (long long) (mn2 + mn3), (long long) (mn3 + mn1)}) * 2 << endl;
}