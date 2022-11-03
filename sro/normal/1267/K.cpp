#include<bits/stdc++.h>
#define ll long long
#define FIO "K"
using namespace std;

const int N=25;

int T;
ll n;
int cnt[N],st[N],t;
int a[N];
ll fac[N];

inline ll calc(){
  ll ret=1;
  for(int i=t;i;i--){
    ret*=t-max(1,st[i])+1-(t-i);
  }
  for(int i=0;i<=t;i++)ret/=fac[cnt[i]];
  //printf("return %lld\n",ret);
  return ret;
}


int main(){
  fac[0]=1;
  for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
  int T;scanf("%d",&T);
  while(T--){
    scanf("%lld",&n);
    memset(cnt,0,sizeof cnt);
    t=0;
    for(int i=2;n;i++){
      st[++t]=n%i;
      cnt[st[t]]++;
      n/=i;
    }
    sort(st+1,st+t+1);

    //printf("t=%d :",t); for(int i=1;i<=t;i++)printf("%d%c",st[i],i^t?' ':'\n');

    ll ans=calc();
    if(cnt[0]){
      cnt[0]--;
      for(int i=1;i<t;i++)st[i]=st[i+1];
      t--;
      ans-=calc();
    }
    printf("%lld\n",ans-1);
      
  }
  return 0;
}