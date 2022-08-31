#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    long long x;
    cin >> n >> m >> x;
    x--;
    int r = x % n;
    int c = x / n;
    long long y = (long long) r * m + c + 1;
    cout << y << endl;
  }
}