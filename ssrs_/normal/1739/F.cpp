#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
//https://ei1333.github.io/library/structure/trie/trie.hpp
template < int char_size >
struct TrieNode {
  int nxt[char_size];

  int exist;
  vector< int > accept;
  int sum;
  TrieNode(): exist(0), sum(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

template < int char_size, int margin >
struct Trie {
  using Node = TrieNode< char_size >;

  vector< Node > nodes;
  int root;

  Trie(): root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id, int weight) {
    nodes[node].accept.push_back(id);
    nodes[node].sum += weight;
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const string &str, int str_index, int node_index, int id, int weight) {
    if (str_index == str.size()) {
      update_direct(node_index, id, weight);
    } else {
      const int c = str[str_index] - margin;
      if (nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int)nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id, weight);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id, int weight) {
    add(str, 0, 0, id, weight);
  }

  void add(const string &str, int weight) {
    add(str, nodes[0].exist, weight);
  }

  void query(const string &str, const function< void(int) > &f,
             int str_index, int node_index) {
    for (auto &idx: nodes[node_index].accept) f(idx);
    if (str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - margin;
      if (nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int count() const {
    return (nodes[0].exist);
  }

  int size() const {
    return ((int)nodes.size());
  }
};
//https://ei1333.github.io/library/string/aho-corasick.hpp
template < int char_size, int margin >
struct AhoCorasick: Trie< char_size + 1, margin > {
  using Trie< char_size + 1, margin >::Trie;

  const int FAIL = char_size;
  vector< int > correct;

  void build(bool heavy = true) {
    correct.resize(this->size());
    for (int i = 0; i < this->size(); i++) {
      correct[i] = (int)this->nodes[i].sum;
    }
    queue< int > que;
    for (int i = 0; i <= char_size; i++) {
      if (~this->nodes[0].nxt[i]) {
        this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(this->nodes[0].nxt[i]);
      } else {
        this->nodes[0].nxt[i] = 0;
      }
    }
    while (!que.empty()) {
      auto &now = this->nodes[que.front()];
      int fail  = now.nxt[FAIL];
      correct[que.front()] += correct[fail];
      que.pop();
      for (int i = 0; i < char_size; i++) {
        if (~now.nxt[i]) {
          this->nodes[now.nxt[i]].nxt[FAIL] =
              this->nodes[fail].nxt[i];
          if (heavy) {
            auto &u = this->nodes[now.nxt[i]].accept;
            auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
            vector< int > accept;
            set_union(begin(u), end(u), begin(v), end(v),
                      back_inserter(accept));
            u = accept;
          }
          que.emplace(now.nxt[i]);
        } else {
          now.nxt[i] = this->nodes[fail].nxt[i];
        }
      }
    }
  }

  map< int, int > match(const string &str, int now = 0) {
    map< int, int > result;
    for (auto &c: str) {
      now = this->nodes[now].nxt[c - margin];
      for (auto &v: this->nodes[now].accept) result[v] += 1;
    }
    return result;
  }

  pair< int64_t, int > move(const char &c, int now = 0) {
    now = this->nodes[now].nxt[c - margin];
    return {correct[now], now};
  }

  pair< int64_t, int > move(const string &str, int now = 0) {
    int64_t sum = 0;
    for (auto &c: str) {
      auto nxt = move(c, now);
      sum += nxt.first;
      now = nxt.second;
    }
    return {sum, now};
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> c[i] >> s[i];
  }
  map<string, int> mp;
  for (int i = 0; i < n; i++){
    int L = s[i].size();
    vector<vector<int>> E(12);
    for (int j = 0; j < L - 1; j++){
      int u = s[i][j] - 'a';
      int v = s[i][j + 1] - 'a';
      E[u].push_back(v);
      E[v].push_back(u);
    }
    for (int j = 0; j < 12; j++){
      sort(E[j].begin(), E[j].end());
      E[j].erase(unique(E[j].begin(), E[j].end()), E[j].end());
    }
    bool ok = true;
    int t = -1;
    for (int j = 0; j < 12; j++){
      if (E[j].size() > 2){
        ok = false;
      }
      if (E[j].size() == 1){
        t = j;
      }
    }
    if (ok && t != -1){
      vector<int> id;
      id.push_back(t);
      id.push_back(E[t][0]);
      while (true){
        int u = id[id.size() - 2];
        int v = id[id.size() - 1];
        if (E[v].size() == 1){
          break;
        }
        int w = E[v][0] ^ E[v][1] ^ u;
        id.push_back(w);
      }
      int sz = id.size();
      string s2;
      for (int j = 0; j < sz; j++){
        s2 += 'a' + id[j];
      }
      mp[s2] += c[i];
      string s3 = s2;
      reverse(s3.begin(), s3.end());
      if (s2 != s3){
        mp[s3] += c[i];
      }
    }
  }
  AhoCorasick<12, 'a'> A;
  for (auto P : mp){
    A.add(P.first, P.second);
  }
  A.build();
  int V = A.size();
  vector<vector<int>> dp(1 << 12, vector<int>(V, -INF));
  vector<vector<pair<int, int>>> pr(1 << 12, vector<pair<int, int>>(V));
  dp[0][0] = 0;
  for (int i = 0; i < (1 << 12); i++){
    for (int j = 0; j < V; j++){
      if (dp[i][j] != -INF){
        for (int k = 0; k < 12; k++){
          if ((i >> k & 1) == 0){
            int i2 = i | (1 << k);
            pair<int, int> P = A.move('a' + k, j);
            int j2 = P.second;
            if (dp[i2][j2] < dp[i][j] + P.first){
              dp[i2][j2] = dp[i][j] + P.first;
              pr[i2][j2] = make_pair(i, j);
            }
          }
        }
      }
    }
  }
  int r = 0;
  for (int i = 0; i < V; i++){
    if (dp[(1 << 12) - 1][i] > dp[(1 << 12) - 1][r]){
      r = i;
    }
  }
  int ci = (1 << 12) - 1;
  int cj = r;
  string ans;
  for (int i = 0; i < 12; i++){
    int i2 = pr[ci][cj].first;
    int j2 = pr[ci][cj].second;
    int p = __builtin_ctz(ci ^ i2);
    ans += 'a' + p;
    ci = i2;
    cj = j2;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}