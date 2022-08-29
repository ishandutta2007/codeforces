#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, s;
    cin >> n >> s;
    cout << s / (n / 2 + 1) << endl;
  }
}