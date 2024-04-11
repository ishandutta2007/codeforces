#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> p(21000, true);
  for (int i = 2; i < 21000; i++){
    if (p[i]){
      for (int j = i * 2; j < 21000; j += i){
        p[j] = false;
      }
    }
  }
  vector<int> prime;
  for (int i = 2; i < 21000; i++){
    if (p[i]){
      prime.push_back(i);
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int d;
    cin >> d;
    int a = *upper_bound(prime.begin(), prime.end(), d);
    int b = *lower_bound(prime.begin(), prime.end(), a + d);
    cout << a * b << endl;
  }
}