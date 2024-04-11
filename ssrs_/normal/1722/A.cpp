#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string s2 = "Timur";
    sort(s2.begin(), s2.end());
    if (s == s2){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}