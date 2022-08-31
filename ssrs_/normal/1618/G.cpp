#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  vector<int> k(q);
  for (int i = 0; i < q; i++){
    cin >> k[i];
  }
  vector<pair<int, int>> P;
  for (int i = 0; i < n; i++){
    P.push_back(make_pair(a[i], 1));
  }
  for (int i = 0; i < m; i++){
    P.push_back(make_pair(b[i], 0));
  }
  sort(P.begin(), P.end());
  vector<pair<int, int>> D;
  for (int i = 0; i < n + m - 1; i++){
    D.push_back(make_pair(P[i + 1].first - P[i].first, i));
  }
  sort(D.begin(), D.end());
  vector<int> S(n + m + 1, 0);
  for (int i = 0; i < n + m; i++){
    if (P[i].second == 1){
      S[i + 1]++;
    }
  }
  for (int i = 1; i <= n + m; i++){
    S[i] += S[i - 1];
  }
  vector<long long> S2(n + m + 1, 0);
  for (int i = 0; i < n + m; i++){
    S2[i + 1] += P[i].first;
  }
  for (int i = 1; i <= n + m; i++){
    S2[i] += S2[i - 1];
  }
  set<int> st;
  for (int i = 0; i <= n + m; i++){
    st.insert(i);
  }
  vector<pair<int, int>> Q(q);
  for (int i = 0; i < q; i++){
    Q[i] = make_pair(k[i], i);
  }
  sort(Q.begin(), Q.end());
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  vector<long long> ans(q);
  int p = 0;
  for (int i = 0; i < q; i++){
    int c = Q[i].first;
    int id = Q[i].second;
    while (p < n + m - 1){
      if (D[p].first > c){
        break;
      }
      int pos = D[p].second;
      pos++;
      int L = *prev(st.lower_bound(pos));
      int R = *st.upper_bound(pos);
      sum -= S2[pos] - S2[pos - (S[pos] - S[L])];
      sum -= S2[R] - S2[R - (S[R] - S[pos])];
      sum += S2[R] - S2[R - (S[R] - S[L])];
      st.erase(pos);
      p++;
    }
    ans[id] = sum;
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << "\n";
  }
}