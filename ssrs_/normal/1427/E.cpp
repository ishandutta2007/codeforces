#include <bits/stdc++.h>
using namespace std;
int main(){
  random_device rnd;
  mt19937 mt(rnd());
  long long x;
  cin >> x;
  vector<pair<long long, long long>> S;
  unordered_map<long long, bitset<1000>> mp;
  set<pair<long long, long long>> st;
  for (int i = 0; i < 1000; i++){
    long long m = (long long) mt() % 100000 * 100000 + mt() % 100000;
    S.push_back(make_pair(m * x, m));
    bitset<1000> N(0);
    N.set(i);
    long long tmp = m * x;
    for (auto itr = st.rbegin(); itr != st.rend(); itr++){
      long long y = (*itr).first;
      if (tmp > (tmp ^ y)){
        tmp ^= y;
        N ^= mp[y];
      }
    }
    if (tmp > 0){
      mp[tmp] = N;
      st.insert(make_pair(tmp, i));
    }
  }
  assert(mp.count(1));
  vector<long long> use;
  for (int i = 0; i < 1000; i++){
    if (mp[1][i]){
      use.push_back(S[i].second);
    }
  }
  vector<tuple<long long, char, long long>> op;
  op.push_back(make_tuple(x, '^', x));
  for (int i = 0; i < 40; i++){
    op.push_back(make_tuple(x << i, '+', x << i));
  }
  int cnt = use.size();
  for (int i = 0; i < cnt; i++){
    long long tmp = 0;
    for (int j = 0; j < 40; j++){
      if (use[i] >> j & 1){
        op.push_back(make_tuple(tmp, '+', x << j));
        tmp += x << j;
      }
    }
  }
  long long X = use[0] * x;
  for (int i = 1; i < cnt; i++){
    op.push_back(make_tuple(X, '^', use[i] * x));
    X ^= use[i] * x;
  }
  int q = op.size();
  cout << q << endl;
  for (int i = 0; i < q; i++){
    cout << get<0>(op[i]) << ' ' << get<1>(op[i]) << ' ' << get<2>(op[i]) << endl;
  }
}