#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100100;
int trie[MAXN][30];
int word[MAXN];
int cnt = 0;
int get(int n, char c) {
  int &r = trie[n][c - 'a'];
  if (!r) r = ++cnt;
  return r;
}


vector<int> v[MAXN];
vector<int> go(int node, int length) {
  vector<int> *lengths = v + node;
  if (word[node]) {
    lengths->push_back(length);
  }
  for(int i = 0; i < 30; ++i) if (trie[node][i]) {
    vector<int> p = go(trie[node][i], length + 1);

    vector<int> *o = &(p);
    if (lengths->size() < o->size()) {
      // swap(lengths, o);
    }
    for(auto k: *o) {
      lengths->push_back(k);
    }
  }

  sort(lengths->begin(), lengths->end());
  if (!word[node] && lengths->size() > 0) {
    lengths->pop_back();
    lengths->push_back(length);
  }
  return *lengths;
}

int main() {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int cur = 0;
    for(int j = 0; j < s.size(); ++j) {
      cur = get(cur, s[j]);
    }
    word[cur] = true;
  }

  int ans = 0;
  for(int i = 0; i < 30; ++i) if (trie[0][i]) {
    vector<int> p = go(trie[0][i], 1);
    for(int j: p) {
      ans += j;
    }
  }
  cout << ans << "\n";
}