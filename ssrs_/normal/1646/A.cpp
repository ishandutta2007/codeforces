#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long s;
    cin >> n >> s;
    cout << s / ((long long) n * n) << endl;
  }
}