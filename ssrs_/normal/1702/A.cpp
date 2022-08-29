#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int m;
    cin >> m;
    int c = to_string(m).size();
    int d = stoi("1" + string(c - 1, '0'));
    cout << m - d << endl;
  }
}