#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

int n;
pii pos[1252];
pii vec[1252];
pii so[1252];

int main(){
  scanf("%d",&n);
  REP(i,n){
    int x,y;
    scanf("%d%d",&x,&y);
    pos[i] = pii(x,y);
  }
  REP(i,n){
    int a,b;
    scanf("%d%d",&a,&b);
    vec[i] = pii(a,b);
  }
  sort(vec, vec+n);
  REP(i,n){
    int tx = pos[0].first + vec[i].first;
    int ty = pos[0].second+ vec[i].second;
    REP(j,n){
      so[j].first = tx - pos[j].first;
      so[j].second= ty - pos[j].second;
    }
    sort(so,so+n);
    bool eq = true;
    REP(j,n)eq = eq && (vec[j] == so[j]);
    if(eq){
      printf("%d %d\n",tx,ty);
      break;
    }
  }
  return 0;
}