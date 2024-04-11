#include <bits/stdc++.h>
using namespace std;
const int N = 128;

int h , cnt;
vector<int> e[N];

bool query(int x) {
  if (cnt == 16) {
    cout << "! " << x << endl;
    return 1;
  }
  ++ cnt;
  cout << "? " << x << endl;
  int k , y;
  cin >> k;
  for (int i = 0 ; i < k ; ++ i) {
    cin >> y;
    e[x].push_back(y);
  }
  if (k == 2) {
    cout << "! " << x << endl;
    return 1;
  }
  return 0;
}
int getnei(int x) {
  for (auto y : e[x]) {
    if (e[y].size() == 0) {
      return y;
    }
  }
  return 0;
}

deque<int> chain;

void work() {
  scanf("%d" , &h);
  for (int i = 0 ; i < N ; ++ i) {
    e[i].clear();
  }
  cnt = 0;
  int cur = 1;
  if (query(1)) return;
  while (!chain.empty()) chain.pop_back();
  if (e[1].size() == 1) {
    chain.push_back(1);
    int x = 1;
    while (x = getnei(x)) {
      if (query(x)) return;
      chain.push_back(x);
    }
  } else {
    chain.push_back(1);
    int x = 1;
    while (x = getnei(x)) {
      if (query(x)) return;
      chain.push_back(x);
    }
    x = 1;
    while (x = getnei(x)) {
      if (query(x)) return;
      chain.push_front(x);
    }
  }
  int size = chain.size();
  int dep = h - size / 2;
  cur = chain[size / 2];
  while (dep > 4) {
    while (chain.size() > h - dep + 1) {
      chain.pop_back();
    }
    int x = chain.back();
    while (x = getnei(x)) {
      if (query(x)) return;
      chain.push_back(x);
    }
    size = chain.size();
    dep = h - size / 2;
    cur = chain[size / 2];
  }
  cur = getnei(cur);
  if (query(cur)) return;
  queue<int> Q;
  Q.push(cur);
  while (!Q.empty()) {
    int x = Q.front();
    int y; Q.pop();
    while (y = getnei(x)) {
      Q.push(y);
      if (query(y)) return;
    }
  }

}

int main() {
  int T;
  scanf("%d" , &T);
  while (T --) {
    work();
  }
}