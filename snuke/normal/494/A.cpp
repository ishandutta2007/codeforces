#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //<^>v



int main(){
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  int r = -1, cnt = 0;
  rep(i,n) {
    if (s[i] == '#') cnt++, r = i;
  }
  int c = 0;
  rep(i,n) if (s[i] == '(') c++; else c--;
  if (c < 0) {
    puts("-1");
    return 0;
  }
  int x = 1+c;
  c = 0;
  rep(i,n) {
    if (i == r) {
      c -= x;
    } else if (s[i] == '(') {
      c++;
    } else c--;
    if (c < 0) {
      puts("-1");
      return 0;
    }
  }
  rep(i,cnt-1) printf("1\n");
  printf("%d\n",x);
  return 0;
}