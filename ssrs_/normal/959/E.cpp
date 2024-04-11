#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  n--;
  long long x = 0;
  for (int i = 0; i < 60; i++){
    x += ((n >> i) - (n >> (i + 1))) << i;
  }
  cout << x << endl;
}