#include <bits/stdc++.h>

using namespace std;

const int ALPHA = 10;

class node {
 public:
  vector<node*> go;
  vector<int> sum;
  node* fail;
  int id;

  node(int len, int id): id(id) {
    go = vector<node*>(ALPHA, NULL);
    sum = vector<int>(len, 0);
    fail = NULL;
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string l, r;
  int n;
  cin >> l >> r >> n;
  int lenl = (int) l.size(), lenr = (int) r.size();
  vector<node*> automaton;
  auto new_node = [&]() {
    node* a = new node(lenr, (int) automaton.size());
    automaton.push_back(a);
    return a;
  };
  node* root = new_node();
  if (lenl == lenr) {
    bool divided = false;
    node* pl = root;
    node* pr = root;
    for (int i = 0; i < lenl; pl = pl->go[l[i] - '0'], pr = pr->go[r[i] - '0'], ++i) {
      if (divided) {
        for (int j = l[i] - '0'; j < ALPHA; ++j) {
          if (pl->go[j] == NULL) {
            pl->go[j] = new_node();
          }
          if (i == lenl - 1 || j != l[i] - '0') {
            ++pl->go[j]->sum[lenl - i - 1];
          }
        }
        for (int j = 0; j <= r[i] - '0'; ++j) {
          if (pr->go[j] == NULL) {
            pr->go[j] = new_node();
          }
          if (i == lenr - 1 || j != r[i] - '0') {
            ++pr->go[j]->sum[lenr - i - 1];
          }
        }
      } else {
        for (int j = l[i] - '0'; j <= r[i] - '0'; ++j) {
          if (pl->go[j] == NULL) {
            pl->go[j] = new_node();
          }
          if (i == lenl - 1 || (j != l[i] - '0' && j != r[i] - '0')) {
            ++pl->go[j]->sum[lenl - i - 1];
          }
        }
        if (l[i] - '0' != r[i] - '0') {
          divided = true;
        }
      }
    }
  } else {
    node* pl = root;
    for (int i = 0; i < lenl; pl = pl->go[l[i] - '0'], ++i) {
      for (int j = l[i] - '0'; j < ALPHA; ++j) {
        if (pl->go[j] == NULL) {
          pl->go[j] = new_node();
        }
        if (i == lenl - 1 || j != l[i] - '0') {
          ++pl->go[j]->sum[lenl - i - 1];
        }
      }
    }
    node* pr = root;
    for (int i = 0; i < lenr; pr = pr->go[r[i] - '0'], ++i) {
      for (int j = !i; j <= r[i] - '0'; ++j) {
        if (pr->go[j] == NULL) {
          pr->go[j] = new_node();
        }
        if (i == lenr - 1 || j != r[i] - '0') {
          ++pr->go[j]->sum[lenr - i - 1];
        }
      }
    }
    for (int i = lenl + 1; i <= lenr - 1; ++i) {
      for (int j = 1; j < ALPHA; ++j) {
        if (root->go[j] == NULL) {
          root->go[j] = new_node();
        }
        ++root->go[j]->sum[i - 1];
      }
    }
  }
  root->fail = root;
  queue<node*> q;
  for (int i = 0; i < ALPHA; ++i) {
    if (root->go[i] == NULL) {
      root->go[i] = root;
    } else {
      root->go[i]->fail = root;
      q.push(root->go[i]);
    }
  }
  while (!q.empty()) {
    node* x = q.front();
    q.pop();
    for (int i = 0; i < lenr; ++i) {
      x->sum[i] += x->fail->sum[i];
    }
    for (int i = 0; i < ALPHA; ++i) {
      if (x->go[i] == NULL) {
        x->go[i] = x->fail->go[i];
      } else {
        x->go[i]->fail = x->fail->go[i];
        q.push(x->go[i]);
      }
    }
  }
  for (auto x : automaton) {
    for (int i = 1; i < lenr; ++i) {
      x->sum[i] += x->sum[i - 1];
    }
  }
  int m = automaton.size();
  vector<vector<int>> dp(n + 1, vector<int>(m, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (~dp[i][j]) {
        for (int k = 0; k < ALPHA; ++k) {
          int jj = automaton[j]->go[k]->id;
          dp[i + 1][jj] = max(dp[i + 1][jj], dp[i][j] + automaton[jj]->sum[min(lenr - 1, n - i - 1)]);
        }
      }
    }
  }
  int ans = *max_element(dp[n].begin(), dp[n].end());
  cout << ans << "\n";
  vector<vector<bool>> best(n + 1, vector<bool>(m));
  for (int i = 0; i < m; ++i) {
    if (dp[n][i] == ans) {
      best[n][i] = true;
    }
  }
  for (int i = n - 1; ~i; --i) {
    for (int j = 0; j < m; ++j) {
      if (~dp[i][j]) {
        for (int k = 0; k < ALPHA; ++k) {
          int jj = automaton[j]->go[k]->id;
          if (best[i + 1][jj] && dp[i + 1][jj] == dp[i][j] + automaton[jj]->sum[min(lenr - 1, n - i - 1)]) {
            best[i][j] = true;
            break;
          }
        }
      }
    }
  }
  int x = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < ALPHA; ++j) {
      int xx = automaton[x]->go[j]->id;
      if (best[i + 1][xx] && dp[i + 1][xx] == dp[i][x] + automaton[xx]->sum[min(lenr - 1, n - i - 1)]) {
        cout << j;
        x = xx;
        break;
      }
    }
  }
  cout << "\n";
  return 0;
}