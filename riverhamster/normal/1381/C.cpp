#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
  char ch; x = 0;
  int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 100005;
int b[N];

priority_queue<pair<int, int> > q;
vector<int> pos[N];

int main(){
//  File("c");
  int T;
  gi(T);
  while(T--){
    int n, x, y, ex = 0;
    gi(n); gi(x); gi(y);
    for(int i=1; i<=n+1; i++) pos[i].clear();
    q = priority_queue<pair<int, int> >();
    for(int i=1; i<=n; i++){
      int v; gi(v);
      pos[v].push_back(i);
    }
    for(int i=1; i<=n+1; i++)
      if(pos[i].empty()) ex = i;
      else q.emplace(pos[i].size(), i);
    fill_n(b + 1, n, ex);
    for(int i=1; i<=x; i++){
      auto p = q.top(); q.pop();
      --p.first;
      b[pos[p.second].back()] = p.second;
      pos[p.second].pop_back();
      if(p.first != 0) q.push(p);
    }
    int cnt = y - x;
    static int p[N], col[N];
    int pc = 0;
    for(int i=1; i<=n+1; i++)
      for(int v : pos[i]){
        p[pc] = v;
        col[pc] = i;
        ++pc;
      }
    int shift = 0;
    if(q.top().first * 2 <= pc) shift = q.top().first;
    else shift = pc - q.top().first;
    int avail = 0;
    for(int i=0; i<pc; i++)
      if(col[i] != col[(i + shift) % pc]) ++avail;
    if(avail < cnt) puts("NO");
    else{
      puts("YES");
      int rc = 0;
      if(cnt != 0)
        for(int i=0; i<pc; i++)
          if(col[i] != col[(i + shift) % pc]){
            b[p[(i + shift) % pc]] = col[i];
            ++rc;
            if(rc == cnt) break;
          }
      for(int i=1; i<=n; i++) printf("%d ", b[i]);
      puts("");
    }
  }
  return 0;
}