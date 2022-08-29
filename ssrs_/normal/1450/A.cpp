#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    cout << a << endl;
  }
}