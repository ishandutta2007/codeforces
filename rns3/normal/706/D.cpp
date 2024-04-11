#include <bits/stdc++.h>
using namespace std;

const int M = 200001 * 31;

int sum[M], nxt[M][2];
int id = 0;

int go(int x, int d) {
  if(!nxt[x][d]) {
    nxt[x][d] = ++id;
    return id;
  }
  return nxt[x][d];
}


void insert(int x, int sign) {
  int cur = 0;
  for(int i = 30; i >= 0; i --) {
    sum[cur] += sign;
    int y = (x & (1<<i));
    cur = go(cur, y > 0);
  }
  sum[cur] += sign;
}

int find(int x) {
  int cur = 0, res = 0;
  for(int i = 30; i >= 0; i --) {
    int y = x & (1<<i);
    if(y > 0) {
      if(nxt[cur][0] && sum[nxt[cur][0]]) {
        cur = nxt[cur][0];
        res += (1<<i);
      }
      else cur = nxt[cur][1];
    }
    else {
      if(nxt[cur][1] && sum[nxt[cur][1]]) {
        cur = nxt[cur][1];
        res += (1<<i);
      }
      else cur = nxt[cur][0];
    }
  }
  return res;
}

int main() {
  ///freopen("3.in", "r", stdin);
  int q;
  scanf("%d", &q);
  insert(0, 1);
  while(q --) {
    char s[10];
    int x;
    scanf("%s %d", s, &x);
    if(s[0] == '+') insert(x, 1);
    else if(s[0] == '-') insert(x, -1);
    else {
      int y = find(x);
      printf("%d\n", y);
    }
  }
}