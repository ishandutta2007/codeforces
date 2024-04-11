#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  queue<int> Q;
  for (int i = 0; i < n; i++){
    Q.push(i);
  }
  vector<int> p(n, -1);
  for (int i = 0; i < n - 1; i++){
    int a = Q.front();
    Q.pop();
    int b = Q.front();
    Q.pop();
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int ans1;
    cin >> ans1;
    cout << "? " << b + 1 << " "  << a + 1 << endl;
    int ans2;
    cin >> ans2;
    if (ans1 > ans2){
      p[a] = ans1;
      Q.push(b);
    } else {
      p[b] = ans2;
      Q.push(a);
    }
  }
  vector<bool> used(n + 1, false);
  for (int i = 0; i < n; i++){
    if (p[i] != -1){
      used[p[i]] = true;
    }
  }
  int last = 0;
  for (int i = 1; i <= n; i++){
    if (!used[i]){
      last = i;
    }
  }
  for (int i = 0; i < n; i++){
    if (p[i] == -1){
      p[i] = last;
    }
  }
  cout << "!";
  for (int i = 0; i < n; i++){
    cout << ' ' << p[i];
  }
  cout << endl;
}