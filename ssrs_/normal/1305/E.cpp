#include <bits/stdc++.h>
using namespace std;
int f(int n){
  if (n % 2 == 0){
    return (n / 2 - 1) * n / 2;
  } else {
    return (n - 1) * (n - 1) / 4;
  }
}
int main(){
  int n, m;
  cin >> n >> m;
  if (m > f(n)){
    cout << -1;
  } else {
    vector<int> a;
    int i = 1;
    while (f(i) <= m){
      a.push_back(i);
      i++;
    }
    i--;
    int L = m - f(i);
    if (L != 0){
      a.push_back(2 * (i - L));
      i++;
    }
    int d = a[i - 1] + 1;
    for (int j = i; j < n; j++){
      a.push_back(a[a.size() - 1] + d);
    }
    for (int j = 0; j < n; j++){
      cout << a[j] << ' ';
    }
  }
}
      //n=100,m=9->i=7; 
    //n=100,m=2449->i=99