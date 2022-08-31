#include <bits/stdc++.h>
using namespace std;
int main(){
  random_device rnd;
  mt19937 mt(rnd());
  int n;
  cin >> n;
  vector<string> S(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> S[i] >> t[i];
  }
  int e = 0;
  for (int i = 0; i < n; i++){
    if (t[i] == 1){
      e++;
    }
  }
  set<string> st1;
  for (int i = 1; i <= e; i++){
    st1.insert(to_string(i));
  }
  set<string> st2;
  for (int i = e + 1; i <= n; i++){
    st2.insert(to_string(i));
  }
  string X;
  while (true){
    X.clear();
    for (int i = 0; i < 6; i++){
      X += (char) ('a' + mt() % 26);
    }
    bool ok = true;
    for (int i = 0; i < n; i++){
      if (X == S[i]){
        ok = false;
      }
    }
    if (ok){
      break;
    }
  }
  vector<bool> ok(n, false);
  for (int i = 0; i < n; i++){
    if (t[i] == 1 && st1.count(S[i]) == 1){
      st1.erase(S[i]);
      ok[i] = true;
    }
    if (t[i] == 0 && st2.count(S[i]) == 1){
      st2.erase(S[i]);
      ok[i] = true;
    }
  }
  vector<string> C(n);
  for (int i = 0; i < n; i++){
    if (!ok[i]){
      if (t[i] == 1){
        assert(!st1.empty());
        C[i] = *st1.begin();
        st1.erase(st1.begin());
      }
      if (t[i] == 0){
        assert(!st2.empty());
        C[i] = *st2.begin();
        st2.erase(st2.begin());
      }
    }
  }
  vector<string> V;
  for (int i = 0; i < n; i++){
    if (!ok[i]){
      V.push_back(S[i]);
      V.push_back(C[i]);
    }
  }
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());
  int cnt = V.size();
  vector<int> a, b;
  int m = 0;
  for (int i = 0; i < n; i++){
    if (!ok[i]){
      m++;
      a.push_back(lower_bound(V.begin(), V.end(), S[i]) - V.begin());
      b.push_back(lower_bound(V.begin(), V.end(), C[i]) - V.begin());
    }
  }
  vector<vector<int>> E(cnt);
  for (int i = 0; i < m; i++){
    E[a[i]].push_back(b[i]);
    assert(E[a[i]].size() == 1);
  }
  vector<int> in(cnt, 0);
  for (int i = 0; i < cnt; i++){
    for (int j : E[i]){
      in[j]++;
    }
  }
  for (int i = 0; i < cnt; i++){
    assert(in[i] <= 1);
  }
  vector<pair<string, string>> ans;
  vector<bool> used(cnt, false);
  for (int i = 0; i < cnt; i++){
    if (in[i] == 0){
      vector<int> id = {i};
      while (true){
        int v = id.back();
        used[v] = true;
        if (E[v].empty()){
          break;
        }
        assert(E[v].size() == 1);
        id.push_back(E[v][0]);
      }
      int sz = id.size();
      for (int j = sz - 2; j >= 0; j--){
        ans.push_back(make_pair(V[id[j]], V[id[j + 1]]));
      }
    }
  }
  vector<int> A, B;
  for (int i = 0; i < cnt; i++){
    if (!used[i]){
      if (stoi(V[i]) <= e){
        A.push_back(i);
      } else {
        B.push_back(i);
      }
    }
  }
  assert(A.size() == B.size());
  int sz = A.size();
  if (sz > 0){
    if (ans.empty()){
      ans.push_back(make_pair(V[B[sz - 1]], X));
      for (int i = sz - 1; i >= 0; i--){
        ans.push_back(make_pair(V[A[i]], V[B[i]]));
        if (i > 0){
          ans.push_back(make_pair(V[B[i - 1]], V[A[i]]));
        }
      }
      ans.push_back(make_pair(X, V[A[0]]));
    } else {
      string Y = ans[0].second;
      if (stoi(Y) > e){
        swap(A, B);
      }
      ans[0].second = V[A[0]];
      vector<pair<string, string>> ans2;
      ans2.push_back(make_pair(V[B[sz - 1]], Y));
      for (int i = sz - 1; i >= 0; i--){
        ans2.push_back(make_pair(V[A[i]], V[B[i]]));
        if (i > 0){
          ans2.push_back(make_pair(V[B[i - 1]], V[A[i]]));
        }
      }
      for (auto P : ans){
        ans2.push_back(P);
      }
      swap(ans, ans2);
    }
  }
  int L = ans.size();
  cout << L << endl;
  for (int i = 0; i < L; i++){
    cout << "move " << ans[i].first << ' ' << ans[i].second << endl;
  }
}