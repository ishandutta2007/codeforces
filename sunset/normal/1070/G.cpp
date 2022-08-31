#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> hero(n, make_pair(-1, -1));
  int left = n, right = -1;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    left = min(left, x);
    right = max(right, x);
    cin >> hero[x].first;
    hero[x].second = i;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> gor(n, vector<pair<int, int>> (n));
  vector<vector<pair<int, int>>> gol(n, vector<pair<int, int>> (n));
  for (int l = 0; l < n; ++l) {
    gor[l][l] = make_pair(a[l], a[l]);
    for (int r = l + 1; r < n; ++r) {
      gor[l][r].first = min(gor[l][r - 1].first, gor[l][r - 1].second + a[r]);
      gor[l][r].second = gor[l][r - 1].second + a[r];
    }
  }
  for (int r = n - 1; ~r; --r) {
    gol[r][r] = make_pair(a[r], a[r]);
    for (int l = r - 1; ~l; --l) {
      gol[r][l].first = min(gol[r][l + 1].first, gol[r][l + 1].second + a[l]);
      gol[r][l].second = gol[r][l + 1].second + a[l];
    }
  }
  for (int meet = 0; meet < n; ++meet) {
    if (left <= meet) {
      vector<int> dpl(n, -1), dpr(n, -1);
      for (int i = meet; ~i; --i) {
        if (~hero[i].first) {
          if (hero[i].first + gor[i][meet].first >= 0) {
            dpl[i] = n;
          } else {
            for (int j = i + 1; j <= meet; ++j) {
              if (~dpl[j] && hero[i].first + gor[i][j - 1].first >= 0) {
                dpl[i] = j;
                break;
              }
            }
          }
        }
      }
      for (int i = meet + 1; i < n; ++i) {
        if (~hero[i].first) {
          if (hero[i].first + gol[i][meet + 1].first >= 0) {
            dpr[i] = n;
          } else {
            for (int j = i - 1; j > meet; --j) {
              if (~dpr[j] && hero[i].first + gol[i][j + 1].first >= 0) {
                dpr[i] = j;
                break;
              }
            }
          }
        }
      }
      if (~dpl[left] && (right <= meet || ~dpr[right])) {
        cout << meet + 1 << endl;
        vector<bool> visit(m);
        vector<int> print;
        if (right > meet) {
          for (int i = right; i != n; i = dpr[i]) {
            print.push_back(hero[i].second);
            visit[hero[i].second] = true;
          }
        }
        for (int i = left; i != n; i = dpl[i]) {
          print.push_back(hero[i].second);
          visit[hero[i].second] = true;
        }
        reverse(print.begin(), print.end());
        for (int i = 0; i < m; ++i) {
          if (!visit[i]) {
            print.push_back(i);
          }
        }
        for (int i = 0; i < m; ++i) {
          cout << print[i] + 1;
          if (i + 1 < m) {
            cout << " ";
          }
        }
        cout << endl;
        return 0;
      }
    }
    if (right >= meet) {
      vector<int> dpl(n, -1), dpr(n, -1);
      for (int i = meet - 1; ~i; --i) {
        if (~hero[i].first) {
          if (hero[i].first + gor[i][meet - 1].first >= 0) {
            dpl[i] = n;
          } else {
            for (int j = i + 1; j < meet; ++j) {
              if (~dpl[j] && hero[i].first + gor[i][j - 1].first >= 0) {
                dpl[i] = j;
                break;
              }
            }
          }
        }
      }
      for (int i = meet; i < n; ++i) {
        if (~hero[i].first) {
          if (hero[i].first + gol[i][meet].first >= 0) {
            dpr[i] = n;
          } else {
            for (int j = i - 1; j >= meet; --j) {
              if (~dpr[j] && hero[i].first + gol[i][j + 1].first >= 0) {
                dpr[i] = j;
                break;
              }
            }
          }
        }
      }
      if (~dpr[right] && (left >= meet || ~dpl[left])) {
        cout << meet + 1 << endl;
        vector<bool> visit(m);
        vector<int> print;
        if (left < meet) {
          for (int i = left; i != n; i = dpl[i]) {
            print.push_back(hero[i].second);
            visit[hero[i].second] = true;
          }
        }
        for (int i = right; i != n; i = dpr[i]) {
          print.push_back(hero[i].second);
          visit[hero[i].second] = true;
        }
        reverse(print.begin(), print.end());
        for (int i = 0; i < m; ++i) {
          if (!visit[i]) {
            print.push_back(i);
          }
        }
        for (int i = 0; i < m; ++i) {
          cout << print[i] + 1;
          if (i + 1 < m) {
            cout << " ";
          }
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}