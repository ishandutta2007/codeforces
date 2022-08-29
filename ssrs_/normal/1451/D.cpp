#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long d, k;
    cin >> d >> k;
    for (int j = 0; j <= d; j++){
      long long c = k * j;
      if (c * c + c * c > d * d){
        cout << "Ashish" << endl;
        break;
      }
      if (c * c + (c + k) * (c + k) > d * d){
        cout << "Utkarsh" << endl;
        break;
      }
    }
  }
}