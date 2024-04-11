#include <bits/stdc++.h>
using namespace std;

#define N 100005

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}

inline int getint(){
  int x;
  char c=nc(),b=1;
  if(c == -1)
    return 0;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
  return x;
}

int n, k, q, last, sz;
int a[N], dp[N], rt[N];
vector<int> v[N];

struct node{
    int l, r, cnt;
} node[N*18];

int modify(int rt, int l, int r, int pos) {
    int cur = ++sz;
    node[cur] = node[rt];
    node[cur].cnt ++;
    if (l == r) return cur;
    int m = l + r >> 1;
    if (pos <= m) node[cur].l = modify(node[cur].l, l, m, pos);
    else node[cur].r = modify(node[cur].r, m + 1, r, pos);
    return cur;
}

int query(int st, int en, int l, int r, int k) {
    if (k < l) return 0;
    if (k >= r) return node[en].cnt - node[st].cnt;
    int m = l + r >> 1;
    return query(node[st].l, node[en].l, l, m, k) + query(node[st].r, node[en].r, m + 1, r, k);
}

int main() {
    
    
    
    
    
    
    
    
    
    
    
    n = getint(), k = getint();
    for (int i = 1; i <= n; i ++) {
        a[i] = getint();
        if (v[a[i]].size() >= k) dp[i] = v[a[i]][v[a[i]].size()-k];
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i ++) rt[i] = modify(rt[i-1], 1, n, dp[i] + 1);
    q = getint();
    while (q --) {
        int x, y;
        x = getint(), y = getint();
        x = (x + last) % n + 1;
        y = (y + last) % n + 1;
        if (x > y) swap(x, y);
        last = query(rt[x-1], rt[y], 1, n, x);
        printf("%d\n", last);
    }
    return 0;
}