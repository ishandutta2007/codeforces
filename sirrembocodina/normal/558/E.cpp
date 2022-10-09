#include <bits/stdc++.h>

using namespace std;

const int tree_sz = 1 << 18;

struct vertex {
  int sum[26];
  int buffer[26];
  vertex() {
    for(int i = 0; i < 26; i++) {
      sum[i] = 0;
      buffer[i] = -1;
    }
    //lol
  }
};

string s;
vector<vertex> tree(tree_sz);

void build_tree(int ind, int l, int r) {
  if(l == r - 1) {
    tree[ind].sum[s[l] - 'a'] = 1;
    return ;
  }
  else {
    int middle = (l + r) / 2;
    build_tree(2 * ind + 1, l ,middle);
    build_tree(2 * ind + 2, middle, r);
    for(int i = 0; i < 26; i++) {
      tree[ind].sum[i] = tree[2 * ind + 1].sum[i] + tree[2 * ind + 2].sum[i];
    }
  }
}

void upd(int ind, int l, int r, int i) {
  if(tree[ind].buffer[i] != -1) {
    tree[ind].sum[i] = tree[ind].buffer[i] * (r - l);
    if(l != r - 1) {
      tree[2 * ind + 2].buffer[i] = tree[ind].buffer[i];
      tree[2 * ind + 1].buffer[i] = tree[ind].buffer[i];
    }
    tree[ind].buffer[i] = -1;
  }
}

void assign_seg(int ind, int l, int r, int L, int R, int i, int x) {
  upd(ind, l, r, i);
  if(R <= l || r <= L) {
    return ;
  }
  if(L <= l && r <= R) {
    tree[ind].buffer[i] = x;
    upd(ind, l, r, i);
    return;
  }
  int middle = (l + r) / 2;
  assign_seg(2 * ind + 1, l, middle, L, R, i, x);
  assign_seg(2 * ind + 2, middle, r, L, R, i, x);
  tree[ind].sum[i] = tree[2 * ind + 1].sum[i] + tree[2 * ind + 2].sum[i];
}

int sum_seg(int ind, int l, int r, int L, int R, int i) {
  upd(ind, l, r, i);
  if(R <= l || r <= L) {
    return 0;
  }
  if(L <= l && r <= R) {
    return tree[ind].sum[i];
  }
  int middle = (l + r) / 2;
  return sum_seg(2 * ind + 1, l, middle, L, R, i) +
         sum_seg(2 * ind + 2, middle, r, L, R, i);
}

string t;

void push_tree(int ind, int l, int r) {
  for (int i = 0; i < 26; i++) {
    upd(ind, l, r, i);
  }
  if (l == r - 1) {
    for (int i = 0; i < 26; i++) {
      if (tree[ind].sum[i]) {
        t[l] = 'a' + i;
      }
    }
    return;
  }
  int middle = (l + r) / 2;
  push_tree(2 * ind + 1, l, middle);
  push_tree(2 * ind + 2, middle, r);
}

int main() {
  ios_base::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  cin >> s;
  t = s;

  build_tree(0, 0, n);

  for(int q = 0; q < k; q++) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    vector<int> cnt(26);
    for (int i = 0; i < 26; i++) {
      cnt[i] = sum_seg(0, 0, n, l, r, i);
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      assign_seg(0, 0, n, l, r, i, 0);
      if (k == 1) {
        assign_seg(0, 0, n, l + sum, l + sum + cnt[i], i, 1);
      }
      else {
        assign_seg(0, 0, n, r - sum - cnt[i], r - sum, i, 1);
      }
      sum += cnt[i];
    }
  }
  push_tree(0, 0, n);
  cout << t << endl;
}