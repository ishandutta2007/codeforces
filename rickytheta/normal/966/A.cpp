#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int n,m,cl,ce,v;
int l[125252];
int e[125252];
int q;

int main(){
  scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
  REP(i,cl)scanf("%d",l+i);
  REP(i,ce)scanf("%d",e+i);
  scanf("%d",&q);
  REP(_,q){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    if(y1==y2){
      printf("%d\n",abs(x1-x2));
      continue;
    }
    int ans = 1<<30;
    // stairs
    if(cl>0){
      // go to right
      int id = lower_bound(l,l+cl,x1)-l;
      if(id < cl){
        int tmp = 0;
        tmp += abs(l[id]-x1);
        tmp += abs(y2-y1);
        tmp += abs(x2-l[id]);
        CHMIN(ans, tmp);
      }
      // go to left
      id--;
      if(id >= 0){
        int tmp = 0;
        tmp += abs(l[id]-x1);
        tmp += abs(y2-y1);
        tmp += abs(x2-l[id]);
        CHMIN(ans, tmp);
      }
    }
    // elevator
    if(ce>0){
      // go to right
      int id = lower_bound(e,e+ce,x1)-e;
      if(id < ce){
        int tmp = 0;
        tmp += abs(e[id]-x1);
        tmp += (abs(y2-y1)+v-1)/v;
        tmp += abs(x2-e[id]);
        CHMIN(ans, tmp);
      }
      // go to left
      id--;
      if(id >= 0){
        int tmp = 0;
        tmp += abs(e[id]-x1);
        tmp += (abs(y2-y1)+v-1)/v;
        tmp += abs(x2-e[id]);
        CHMIN(ans, tmp);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}