#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;
    if (d12 > d23 + d31 || d23 > d31 + d12 || d31 > d12 + d23){
      cout << "NO" << endl;
    } else if ((d12 + d23 + d31) % 2 == 1){
      cout << "NO" << endl;
    } else if (n <= (d12 + d23 + d31) / 2){
      cout << "NO" << endl;
    } else {
      int s1 = (d12 + d31 - d23) / 2;
      int s2 = (d23 + d12 - d31) / 2;
      int s3 = (d31 + d23 - d12) / 2;
      vector<int> p1 = {0}, p2 = {1}, p3 = {2};
      int V = 3;
      for (int j = 0; j < s1 - 1; j++){
        p1.push_back(V);
        V++;
      }
      for (int j = 0; j < s2 - 1; j++){
        p2.push_back(V);
        V++;
      }
      for (int j = 0; j < s3 - 1; j++){
        p3.push_back(V);
        V++;
      }
      if (s1 == 0){
        p2.push_back(0);
        p3.push_back(0);
      } else if (s2 == 0){
        p3.push_back(1);
        p1.push_back(1);
      } else if (s3 == 0){
        p1.push_back(2);
        p2.push_back(2);
      } else {
        p1.push_back(V);
        p2.push_back(V);
        p3.push_back(V);
        V++;
      }
      cout << "YES" << endl;
      for (int j = 0; j < s1; j++){
        cout << p1[j] + 1 << ' ' << p1[j + 1] + 1 << endl;
      }
      for (int j = 0; j < s2; j++){
        cout << p2[j] + 1 << ' ' << p2[j + 1] + 1 << endl;
      }
      for (int j = 0; j < s3; j++){
        cout << p3[j] + 1 << ' ' << p3[j + 1] + 1 << endl;
      }
      if (V < n){
        for (int j = V; j < n; j++){
          cout << j << ' ' << j + 1 << endl;
        }
      }
    }
  }
}