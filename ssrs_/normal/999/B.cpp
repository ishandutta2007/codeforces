#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string t;
  cin >> t;
  for (int i = 1; i <= n; i++){
    if (n % i == 0){
      reverse(t.begin(), t.begin() + i);
    }
  }
  cout << t << endl;
}