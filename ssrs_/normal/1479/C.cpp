#include <bits/stdc++.h>
using namespace std;
int f(int x){
  int ans = 0;
  while (x > 0){
    x /= 2;
    ans++;
  }
  return ans;
}
int main(){
  int L, R;
  cin >> L >> R;
  if (L == 1 && R == 1){
    cout << "YES" << endl;
    cout << 2 << ' ' << 1 << endl;
    cout << 1 << ' ' << 2 << ' ' << 1 << endl;
    return 0;
  }
  int A = R - L + 1;
  vector<tuple<int, int, int>> E;
  int n = f(A);
  int N = n + 2;
  for (int i = 0; i < n; i++){
    E.push_back(make_tuple(0, i + 2, L));
  }
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      E.push_back(make_tuple(i + 2, j + 2, 1 << i));
    }
  }
  int cnt = 0;
  int tmp = 1;
  while (tmp * 2 < A){
    tmp *= 2;
    cnt++;
  }
  for (int i = 0; i < cnt; i++){
    if ((A >> i & 1) == 1){
      A -= 1 << i;
      E.push_back(make_tuple(i + 2, 1, A - 1));
    }
  }
  E.push_back(make_tuple(1, n + 1, 1));
  int m = E.size();
  for (int i = 0; i < m; i++){
    int a = get<0>(E[i]);
    if (a == 1){
      get<0>(E[i]) = N - 2;
    } else if (2 <= a && a < N - 1){
      get<0>(E[i])--;
    }
    int b = get<1>(E[i]);
    if (b == 1){
      get<1>(E[i]) = N - 2;
    } else if (2 <= b && b < N - 1){
      get<1>(E[i])--;
    }
  }
  cout << "YES" << endl;
  cout << N << ' ' << m << endl;
  for (int i = 0; i < m; i++){
    int a = get<0>(E[i]);
    int b = get<1>(E[i]);
    int c = get<2>(E[i]);
    cout << a + 1 << ' ' << b + 1 << ' ' << c << endl;
  }
}