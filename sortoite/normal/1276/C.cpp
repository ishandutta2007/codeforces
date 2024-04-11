#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef double DO;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

const int inf=0x3f3f3f3f, mod=1000000007;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.), eps=1e-9;

const int NN = 1e6;
pii p[NN];
int sum[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n, m=0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &p[i].x);
  sort(p, p+n);
  for(int i=0, j; i<n; i=j) {
    for(j=i; j<n && p[j].x == p[i].x; j++);
    p[m].x=p[i].x;
    p[m].y=j-i;
    m++;
  }
  sort(p, p+m, [](pii a, pii b) {return a.y>b.y;});
  int tot=0, row, col;
  for(int i=m-1; i>=0; i--) sum[i]=sum[i+1]+p[i].y;
  
  for(int i=1; (LL)i*i<=n; i++) {
    int st=-1, ed=m;
    while(st+1<ed) {
      int md=(st+ed)/2;
      if(p[md].y<i) ed=md;
      else st=md;
    }
    int t=ed*i+sum[ed];
    if(t<(LL)i*i) continue;
    else {
      t=(int)(t/i)*i;
      if(t>tot) {
        tot=t;
        row=i;
        col=t/i;
      }
    }
  }
  cout<<tot<<endl;
  cout<<row<<' '<<col<<endl;
  VI v;
  for(int i=0; i<m; i++) {
    for(int j=1; v.size()<tot && j<=p[i].y && j<=row; j++) v.pb(p[i].x);
  }
  VI t;
  for(int i=0; i<row; i++) {
    t.clear();
    for(int j=i; j<tot; j+=row) t.pb(v[j]);
    rotate(t.begin(), t.begin()+row-1-i, t.end());
    for(auto r:t) printf("%d ", r);
    puts("");
  }
  return 0;
}