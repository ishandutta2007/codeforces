#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    long long k;
    cin >> k;
    long long a = 0;
    for (int j = 1; j < n; j++){
      a += j;
      if (a >= k){
        int count = 0;
        for (int l = 0; l < n - j - 1; l++){
          cout << 'a';
          count++;
        }
        cout << 'b';
        count++;
        a -= k;
        for (int l = 0; l < a; l++){
          cout << 'a';
          count++;
        }
        cout << 'b';
        count++;
        while (count < n){
          cout << 'a';
          count++;
        }
        cout << endl;
        break;
      }
    }
  }
}