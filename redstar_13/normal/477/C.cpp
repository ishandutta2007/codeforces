#include<bits/stdc++.h>
using namespace std;
template<typename kim,typename nam> 
inline void smax(kim &a,nam b){if(a<b) a=b;}

const int NN=2020;
char Str[NN];
char Pat[NN];
int Next[NN];
int Dyna[NN][NN<<1];

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
#endif
  int i,j,k;
  scanf("%s%s",Str,Pat);
  int N,M;
  N=strlen(Str);
  M=strlen(Pat);
  for(i=0; i<N; i++){
    for(j=i,Next[i]=N+1,k=0; j<N && k<M; j++){
      if(Str[j]==Pat[k]) k++;
      if(k==M) Next[i]=j-i+1;
    }
  }
  for(i=0; i<N; i++){
    for(j=0; j<=i; j++){
      smax(Dyna[i+1][j],Dyna[i][j]);
      smax(Dyna[i+1][j+1],Dyna[i][j]);
      if(i+Next[i]<=N){
        smax(Dyna[i+Next[i]][j+Next[i]-M],Dyna[i][j]+1);
      }
    }
  }
  for(i=0; i<=N; i++){
    printf("%d ",Dyna[N][i]);
  }
  puts("");
  return 0;
}