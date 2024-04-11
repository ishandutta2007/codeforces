#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    if (x == 1 || x == 2 || x == 4 || x == 5 || x == 8 || x == 11){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}