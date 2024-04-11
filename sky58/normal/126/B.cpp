#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned ll

#define D 10007

char in[1100000];
ull hs, st[1100000], ed[1100000];
ull pw[1100000];

int main(){
  int i,j,k,l,m,n,ok,res;

  while(scanf("%s",in)==1){
    n = strlen(in);
    res = 0;

    pw[0] = 1;
    rep(i,n+1) pw[i+1] = pw[i]*D;

    st[0] = ed[0] = 0;
    rep(i,n) st[i+1] = st[i]*D + in[i];
    rep(i,n) ed[i+1] = ed[i] + in[n-1-i]*pw[i];

    for(k=n-1;k;k--) if(st[k]==ed[k]){
      ok = 0;
      hs = 0;
      rep(i,k) hs = hs*D + in[i];
      REP(i,k,n-1){
        hs = hs*D + in[i] - in[i-k]*pw[k];
        if(hs==st[k]) ok=1;
      }
      if(ok){res=k; break;}
    }
    
    if(res > 0){
      rep(i,res) putchar(in[i]);
      puts("");
    } else {
      puts("Just a legend");
    }
  }

  return 0;
}