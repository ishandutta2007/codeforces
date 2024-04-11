#include <bits/stdc++.h>
using namespace std;
int main(){
  int a = 0, b = 0, c = 0;
  vector<int> X;
  while (true){
    int s = 2 * (a * b + b * c + c * a);
    X.push_back(s);
    if (s > 1100000000){
      break;
    }
    a++;
    swap(a, b);
    swap(b, c);
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << lower_bound(X.begin(), X.end(), n) - X.begin() << "\n";
  }
}