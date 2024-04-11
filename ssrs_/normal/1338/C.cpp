#include <bits/stdc++.h>
using namespace std;
string f(long long n){
  string ans;
  while (n > 0){
    if (n % 4 == 0){
      ans += '1';
    } else if (n % 4 == 1){
      ans += '0';
    } else {
      ans += n % 4 + '0';
    }
    n = (n - 1) / 4;
  }
  ans += '2';
  reverse(ans.begin(), ans.end());
  return ans;
}
long long bit4inv(string S){
  long long res = 0;
  for (char c : S){
    res *= 4;
    res += c - '0';
  }
  return res;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    if (n <= 3){
      cout << n << endl;
    } else {
      long long a = 1;
      int g = 0;
      while (a <= (n - 1) / 3){
        a = a * 4 + 1;
        g++;
      }
      long long B = (long long) 1 << (g * 2);
      B = B + (n - B) / 3;
      if (n % 3 == 1){
        cout << B << endl;
      } else {
        string S = f((n - 1) / 3);
        long long C = bit4inv(S);
        if (n % 3 == 2){
          cout << C << endl;
        } else {
          cout << (B ^ C) << endl;
        }
      }
    }
  }
}