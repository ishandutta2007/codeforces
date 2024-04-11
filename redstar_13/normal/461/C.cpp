#include <bits/stdc++.h>
using namespace std;
const int NN=200100;
int B[NN];

inline void Update(int u,int d){
  for(;u<NN;u+=u&-u){
    B[u]+=d;
  }
}

inline int Calc(int u,int ans=0){
  for(;u;u-=u&-u){
    ans+=B[u];
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int i,j,k,l,Test,Type,L,R,Len;
  int Start=NN>>1,End,N,Direct=1;
  scanf("%d%d",&N,&Test);
  End=Start+N-1;
  for(i=Start; i<=End; i++) Update(i,1);
  while(Test--){
    scanf("%d",&Type);
    if(Type==1){
      scanf("%d",&Len);
      if(Direct){
        if(Len>(End-Start+1)>>1){
          for(i=Start+Len; i<=End; i++){
            Update(Start+Len-1-(i-(Start+Len)),Calc(i)-Calc(i-1));
          }
          End=Start+Len-1;
          Direct^=1;
        }else{
          for(i=Start; i<=Start+Len-1; i++){
            Update(Start+Len+(Start+Len-1-i),Calc(i)-Calc(i-1));
          }
          Start=Start+Len;
        }
      }else{
        if(Len>(End-Start+1)>>1){
          for(i=Start; i<=End-Len; i++){
            Update(End-Len+1+(End-Len-i),Calc(i)-Calc(i-1));
          }
          Start=End-Len+1;
          Direct^=1;
        }else{
          for(i=End-Len+1; i<=End; i++){
            Update(End-Len-(i-(End-Len+1)),Calc(i)-Calc(i-1));
          }
          End=End-Len;
        }
      }
    }else{
      scanf("%d%d",&L,&R);
      if(Direct){
        printf("%d\n",Calc(Start+R-1)-Calc(Start+L-1));
      }else{
        printf("%d\n",Calc(End-L)-Calc(End-R));
      }
    }
  }
  return 0;
}