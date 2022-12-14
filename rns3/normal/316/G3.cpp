#include <bits/stdc++.h>

using namespace std;

#define SIGMA 37

struct Node {
  int l, r, pardp, chdNum;
  Node *par, *sLink;
  Node *chd[SIGMA];

  Node() {
    l = r = pardp = chdNum = 0;
    par = sLink = NULL;
    for (int i = 0; i < SIGMA; i++) chd[i] = NULL;
  }

  inline int len() { return r - l; }
  inline int depth() { return pardp + len(); }
  inline bool inEdge(int pos) { return pardp <= pos && pos < depth(); }

  void setEdge(Node *child, int l, int r, char *s) {
    chd[s[l] - 'A'] = child;
    chdNum ++;
    child -> par = this;
    child -> pardp = depth();
    child -> l = l, child -> r = r;
  }
};

struct STree {
  char *S;
  int m, jj, tot;
  bool needWalk;
  Node *root, *cur, *needSLink;
  vector <Node> V;
  queue <Node *> Q;

  STree(char *str) {
    S = str;
    m = strlen(S);
    tot = 0;
    V.clear();
    V.reserve(m * 2 + 10);
    root = newNode();
    cur = newNode();
    root -> setEdge(cur, 0, m, S);
    Q.push(cur);
    needSLink = NULL;
    jj = 1;
    needWalk = true;
  }
  Node *newNode() {
    V.push_back(Node());
    return &V[tot ++];
  }
  void walk_down(int j, int i) {
    if (i >= j)
      for (int h = j + cur -> depth(); !cur -> inEdge(i - j); h += cur -> len())
        cur = cur -> chd[S[h] - 'A'];
  }
  void addSLink() {
    if (needSLink) {
      needSLink -> sLink = cur;
      needSLink = NULL;
    }
  }
  void extend(int i) {
    int k, pos;
    char c = S[i + 1];
    Node *leaf, *split;

    for (; jj <= i + 1; jj ++) {
      if (needWalk) {
        if (!cur -> sLink && cur -> par) cur = cur -> par;
        cur = (cur -> sLink) ? cur -> sLink : root;
        walk_down(jj, i);
      }
      needWalk = true;

      k = i - jj + 1;
      if (k == cur -> depth()) {
        addSLink();
        if (cur -> chd[c - 'A']) {
          cur = cur -> chd[c - 'A'];
          needWalk = false;
          break;
        } else {
          leaf = newNode();
          cur -> setEdge(leaf, i + 1, m, S);
          Q.push(leaf);
        }
      } else {
        pos = cur -> l + k - cur -> pardp;
        if (S[pos] == c) {
          addSLink();
          if (pos != i + 1) {
            needWalk = false;
            break;
          }
        } else {
          split = newNode();
          leaf = newNode();
          cur -> par -> setEdge(split, cur -> l, pos, S);
          cur -> par -> chdNum--;
          split -> setEdge(cur, pos, cur -> r, S);
          split -> setEdge(leaf, i + 1, m, S);
          Q.push(leaf);
          cur = split;
          addSLink();
          if (cur -> depth() == 1) cur -> sLink = root;
          else needSLink = cur;
        }
      }
    }
  }
};

#define N 500055

typedef __int64 LL;

int m, n;
char s[N], tmp[N];
int pos[N], en[N];
LL L[11], R[11];

struct RLT {
  LL cnt[11];
  RLT() {
    for (int i = 0; i <= m; i ++) cnt[i] = 0;
  }
  void operator += (const RLT &r) {
    for (int i = 0; i <= m; i ++) cnt[i] += r.cnt[i];
  }
  bool good() {
    for (int i = 0; i <= m; i ++) {
      if (cnt[i] < L[i] || R[i] < cnt[i]) return 0;
    }
    return 1;
  }
};

LL rlt = 0;

RLT DFS(Node *p) {
  RLT ret;
  if (!p -> chdNum) {
    int ps = pos[n - p -> depth()];
    if (ps >= 0) ret.cnt[ps] ++;
  } else {
    for (int i = 0; i < 37; i ++) {
      if (p -> chd[i]) ret += DFS(p -> chd[i]);
    }
  }
  if (ret.good() && s[p -> l] <= 'Z') {
    rlt += min(p -> r, en[pos[p -> l]]) - p -> l;
  }
  return ret;
}

main() {
  n = 0;
  scanf("%s", tmp);
  L[0] = 1, R[0] = 1LL << 60;
  for (int i = 0; tmp[i]; i ++) {
    pos[n] = 0;
    s[n ++] = tmp[i] - 'a' + 'A';
  }
  en[0] = n;
  pos[n] = -1, s[n ++] = 'A' + 26;

  scanf("%d", &m);
  for (int i = 1; i <= m; i ++) {
    scanf("%s %I64d %I64d", tmp, L + i, R + i);
    for (int j = 0; tmp[j]; j ++) {
      pos[n] = i;
      s[n ++] = tmp[j] - 'a' + 'A';
    }
    en[i] = n;
    pos[n] = -1, s[n ++] = 'A' + 26 + i;
  }
  s[n] = 0;

  STree T(s);
  for (int i = 0; i < n - 1; i ++) T.extend(i);

  DFS(T.root);
  printf("%I64d\n", rlt);
}