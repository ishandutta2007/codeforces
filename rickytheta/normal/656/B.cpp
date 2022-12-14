#include <cstdio>

using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)

int main(){
  int n;
  scanf("%d",&n);
  int m[n],r[n];
  REP(i,n)scanf("%d",m+i);
  REP(i,n)scanf("%d",r+i);
  int cnt = 0;
  int bo = 20000000;
  REP(i,bo){
    bool flag = false;
    REP(j,n) flag |= i%m[j]==r[j];
    if(flag)++cnt;
  }
  double ans = (double)cnt/(double)bo;
  printf("%.9lf\n",ans);
  return 0;
}