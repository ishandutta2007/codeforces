#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  set<int> A;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    if (a != 0){
      A.insert(a);
    }
  }
  cout << A.size() << endl;
}