#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n + 1, 1);
  for (int i = 2; i <= n; i++){
    for (int j = i * 2; j <= n; j += i){
      p[j] = i;
    }
  }
  vector<int> count(n + 1, 0);
  for (int i = 1; i <= n; i++){
    count[p[i]]++;
  }
  for (int i = 2; i <= n; i++){
    count[i] += count[i - 1];
  }
  int I = 1;
  for (int i = 2; i <= n; i++){
    while (i > count[I]){
      I++;
    }
    cout << I;
    if (i < n){
      cout << ' ';
    }
  }
}