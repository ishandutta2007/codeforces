#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    int N = abs(a - b) * 2;
    if (a > N || b > N || c > N){
      cout << -1 << endl;
    } else if (c > N / 2){
      cout << c - N / 2 << endl;
    } else {
      cout << c + N / 2 << endl;
    }
  }
}