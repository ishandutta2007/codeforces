#include<bits/stdc++.h>
using namespace std;
const int NN=1000100;
char Str[NN];
char Tmp[NN];
int Pat[NN];
int P[NN];
int Q[NN];
int R[NN];

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
#endif
  int i,j,k,l;
  int N,T,D,K,M,CL;
  scanf("%s%d",Str,&T);
  N=strlen(Str);
  while(T--){
    scanf("%d%d",&K,&D);
    for(i=k=0; i<D; i++){
      for(j=i; j<K; j+=D){
        Pat[k++]=j;
      }
    }
    for(i=0; i<N; i++){
      P[i]=i;
    }
    M=N-K+1;
    k=0;
    while(M>>k) k++;
    CL=1;
    for(i=0; i<K; i++){
      P[i]=Pat[i];
    }
    for(i=k-2; i>=0; i--){
      if(M&(1<<i)){
        for(j=0; j<K+CL; j++){
          R[j]=Q[j]=P[j];
        }
        for(j=CL; j<K+CL; j++){
          P[j]=Q[Pat[j-CL]+CL];
        }
        for(j=0; j<(CL<<1)+K; j++){
          Q[j]=P[j];
        }
        for(j=CL+1; j<(CL<<1)+K; j++){
          P[j]=Q[R[j-(CL+1)]+CL+1];
        }
        CL=(CL<<1)+1;
      }else{
        for(j=0; j<(CL<<1)+K-1; j++){
          Q[j]=P[j];
        }
        for(j=CL; j<(CL<<1)+K-1; j++){
          P[j]=Q[Q[j-CL]+CL];
        }
        CL=(CL<<1);
      }
    }
    for(i=0; i<N; i++){
      Tmp[i]=Str[P[i]];
    }
    for(i=0; i<N; i++){
      Str[i]=Tmp[i];
    }
    printf("%s\n",Str);
  }
  return 0;
}