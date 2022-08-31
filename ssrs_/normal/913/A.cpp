#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  if (n >= 30){
    cout << m << endl;
  } else {
    cout << m % (1 << n) << endl;
  }
}