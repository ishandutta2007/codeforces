#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n, k;
    cin >> n >> k;
    long long S = (n + k - 1) / k * k;
    cout << (S + n - 1) / n << endl;
  }
}