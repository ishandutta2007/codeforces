#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int main(){
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    double n;
    cin >> n;
    cout << 1 / tan(PI / (2 * n)) << endl;
  }
}