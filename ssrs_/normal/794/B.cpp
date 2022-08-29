#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  int n, h;
  cin >> n >> h;
  for (int i = 1; i < n; i++){
    cout << h * sqrt(i / (double) n);
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}