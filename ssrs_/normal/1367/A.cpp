#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string b;
    cin >> b;
    int N = b.size();
    string a;
    for (int i = 0; i < N / 2; i++){
      a += b[i * 2];
    }
    a += b.back();
    cout << a << endl;
  }
}