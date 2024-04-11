#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return b ? "true" : "false";
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef wxh010910
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<set<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    graph[x].insert(y);
    graph[y].insert(x);
  }
  set<pair<int, int>> degrees;
  vector<int> weight(n, 1);
  long long answer = 0;
  for (int i = 0; i < n; ++i) {
    degrees.insert(make_pair(graph[i].size(), i));
  }
  while (degrees.size() > 1) {
    int x = degrees.begin()->second;
    if (graph[x].size() > 1) {
      break;
    }
    int y = *graph[x].begin();
    degrees.erase(make_pair(graph[x].size(), x));
    degrees.erase(make_pair(graph[y].size(), y));
    graph[x].erase(y);
    graph[y].erase(x);
    answer += 2ll * weight[x] * (n - weight[x]);
    weight[y] += weight[x];
    degrees.insert(make_pair(graph[y].size(), y));
  }
  if (degrees.size() == 1) {
    printf("%lld\n", answer >> 1);
    return 0;
  }
  vector<int> id(n, -1);
  vector<vector<int>> adj(n);
  m = 0;
  for (int x = 0; x < n; ++x) {
    for (auto y : graph[x]) {
      adj[x].push_back(y);
    }
    if (adj[x].size() > 2) {
      id[x] = m++;
    }
  }
  if (!m) {
    for (int i = 0; i < n; ++i) {
      if (adj[i].size() == 2) {
        id[i] = m++;
        break;
      }
    }
  }
  vector<vector<vector<vector<int>>>> between(m, vector<vector<vector<int>>> (m));
  for (int x = 0; x < n; ++x) {
    if (~id[x]) {
      for (auto y : adj[x]) {
        if (~id[y]) {
          between[id[x]][id[y]].emplace_back();
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 2 && !~id[i]) {
      vector<int> weights(1, weight[i]);
      vector<int> end(2);
      id[i] = m;
      for (int j = 0; j < 2; ++j) {
        int x = adj[i][j], prev = i;
        while (!~id[x]) {
          weights.push_back(weight[x]);
          id[x] = m;
          int next = adj[x][0] + adj[x][1] - prev;
          prev = x;
          x = next;
        }
        end[j] = x;
        reverse(weights.begin(), weights.end());
      }
      between[id[end[1]]][id[end[0]]].push_back(weights);
    }
  }
  {
    vector<int> new_weight(m);
    for (int i = 0; i < n; ++i) {
      if (id[i] != -1 && id[i] < m) {
        new_weight[id[i]] = weight[i];
      }
    }
    weight = new_weight;
  }
  vector<vector<int>> dist(m, vector<int> (m, n));
  for (int i = 0; i < m; ++i) {
    dist[i][i] = 0;
  }
  vector<pair<int, int>> non_empty;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto &p : between[i][j]) {
        dist[i][j] = dist[j][i] = min(dist[i][j], (int)p.size() + 1);
      }
      if (!between[i][j].empty()) {
        non_empty.emplace_back(i, j);
      }
    }
  }
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < i; ++j) {
      answer += 2ll * weight[i] * weight[j] * dist[i][j];
    }
  }
  vector<vector<vector<vector<long long>>>> sum_weight(m, vector<vector<vector<long long>>> (m));
  vector<vector<vector<vector<long long>>>> sum_dist(m, vector<vector<vector<long long>>> (m));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      sum_weight[i][j].resize(between[i][j].size());
      sum_dist[i][j].resize(between[i][j].size());
      for (int k = 0; k < between[i][j].size(); ++k) {
        sum_weight[i][j][k].resize(between[i][j][k].size() + 1);
        sum_dist[i][j][k].resize(between[i][j][k].size() + 1);
        for (int l = 0; l < between[i][j][k].size(); ++l) {
          sum_weight[i][j][k][l + 1] = sum_weight[i][j][k][l] + between[i][j][k][l];
          sum_dist[i][j][k][l + 1] = sum_dist[i][j][k][l] + (long long)between[i][j][k][l] * l;
        }
      }
    }
  }
  auto solve = [&](int i, int j, int k, int l, int r, int dist, int diff) {
    return dist * (sum_weight[i][j][k][r] - sum_weight[i][j][k][l]) + diff * (sum_dist[i][j][k][r] - sum_dist[i][j][k][l]);
  };
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < between[i][j].size(); ++k) {
        for (int l = 0; l < between[i][j][k].size(); ++l) {
          long long w = between[i][j][k][l];
          for (int ii = 0; ii < m; ++ii) {
            answer += 2ll * w * weight[ii] * min(dist[i][ii] + l + 1, dist[j][ii] + (int)between[i][j][k].size() - l);
          }
          for (auto p : non_empty) {
            int ii = p.first;
            int jj = p.second;
            for (int kk = 0; kk < between[ii][jj].size(); ++kk) {
              if (i == ii && j == jj && k == kk) {
                {
                  int inside = l;
                  int outside = dist[i][j] + between[i][j][k].size() - l + 1;
                  if (inside <= outside) {
                    answer += w * solve(i, j, k, 0, l, inside, -1);
                  } else {
                    int ll = inside - outside + 1 >> 1;
                    answer += w * solve(i, j, k, 0, ll, outside, 1);
                    answer += w * solve(i, j, k, ll, l, inside, -1);
                  }
                }
                {
                  int inside = -l;
                  int outside = dist[i][j] + between[i][j][k].size() + l + 1;
                  int ll = min((int)between[i][j][k].size(), outside - inside + 1 >> 1);
                  answer += w * solve(i, j, k, l, ll, inside, 1);
                  answer += w * solve(i, j, k, ll, between[i][j][k].size(), outside, -1);
                }
              } else {
                int to_ii = min(dist[i][ii] + l + 1, dist[j][ii] + (int)between[i][j][k].size() - l);
                int to_jj = min(dist[i][jj] + l + 1, dist[j][jj] + (int)between[i][j][k].size() - l);
                int ll = min(between[ii][jj][kk].size(), to_jj - to_ii + between[ii][jj][kk].size() + 1 >> 1);
                answer += w * solve(ii, jj, kk, 0, ll, to_ii + 1, 1);
                answer += w * solve(ii, jj, kk, ll, between[ii][jj][kk].size(), to_jj + between[ii][jj][kk].size(), -1);
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", answer >> 1);
  return 0;
}