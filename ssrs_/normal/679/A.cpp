#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> prime = {2, 3, 5, 7, 11, 13, 15, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
  int cnt = 0;
  for (int x : prime){
    cout << x << endl;
    string S;
    cin >> S;
    if (S == "yes"){
      cnt++;
    }
  }
  if (cnt < 2){
    cout << "prime" << endl;
  } else {
    cout << "composite" << endl;
  }
}