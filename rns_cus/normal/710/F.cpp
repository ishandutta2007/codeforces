#include <bits/stdc++.h>
using namespace std;

#define M 300100

int h[M];

const int D = 500;

void make_PI(string &S) {
  int k = 0;
  int m = S.length();
  h[1] = 0;
  for (int i = 2; i <= m; i ++) {
    while (k && S[k] != S[i - 1]) k = h[k];
    if (S[k] == S[i - 1]) k ++;
    h[i] = k;
  }
}

int get(string &S, string &T) {
  int k = 0, res = 0;
  int n = T.length(), m = S.length();
  for (int i = 1; i <= n; i ++) {
    while (k && S[k] != T[i - 1]) k = h[k];
    if (S[k] == T[i - 1]) k ++;
    if (k == m) {
      k = h[k]; res++;
    }
  }
  return res;
}

multiset <string> setv;

char s[M];

#define SIGMA 26

namespace Trie {

  #define v node[u].next[c]
  #define f node[node[u].link].next[c]
  #define idx(c) (c - 'a')

  struct Node {
    int next[SIGMA];
    int link, cnt;
  } node[M];

  int tot;

  int newnode() {
    node[tot].link = 0;
    node[tot].cnt = 0;
    memset(node[tot].next, 0, sizeof(int) * SIGMA);
    return tot ++;
  }

  void init() {
    tot = 0;
    newnode();
  }

  void insert(string &s) {
    int u = 0, len = s.length();
    for (int i = 0; i < len; i ++) {
      int c = idx(s[i]);
      if (!v) v = newnode();
      u = v;
    }
    node[u].cnt++;
  }

  void remove(string &s) {
    int u = 0, len = s.length();
    for (int i = 0; i < len; i ++) {
      int c = idx(s[i]);
      u = v;
    }
    node[u].cnt--;
  }

  string T;
  int len;

  int find(int st) {
    int rlt = 0;
    int u = 0;
    for (int i = st; i < len; i ++) {
      int c = idx(T[i]);

      if (!v) return rlt;

      rlt += node[v].cnt;
      u = v;
    }
    return rlt;
  }

  int count() {
    len = T.length();
    int rlt = 0;
    for (int i = 0; i < len; i++) rlt += find(i);
    return rlt;
  }

  #undef v
  #undef f
}

int main() {
  //freopen("in.txt", "r", stdin);
  int T, type;

  Trie::init();

  for (scanf("%d", &T); T--; ) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%s", s);
      string str = s;
      if (str.length() > D) setv.insert(str);
      else {
        Trie::insert(str);
      }
    }
    else if (type == 2) {
      scanf("%s", s);
      string str = s;
      if (str.length() > D) setv.erase(setv.find(str));
      else {
        Trie::remove(str);
      }
    }
    else {
      scanf("%s", s);
      string str = s;
      int len = str.length();

      Trie::T = str;

      int ans = Trie::count();

      for (multiset <string> :: iterator it = setv.begin(); it != setv.end(); it++) {
        string ss = *it;
        if (ss.length() <= len) {
          make_PI(ss); ans += get(ss, str);
        }
      }
      printf("%d\n", ans); fflush(stdout);
    }
  }
}