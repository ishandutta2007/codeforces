#include<bits/stdc++.h>
#define ll long long
#define FIO "B"
#define GG return puts("0"),0
using namespace std;

const int N=3e5+5;

int n;

char s[N];

int main(){
  scanf("%s",s+1);
  int i=1,j=strlen(s+1);
  while(1){
    //printf("i=%d j=%d \n",i,j);
    if(s[i]!=s[j])GG;
    int ii=i,jj=j;
    while(s[ii+1]==s[i])ii++;
    while(s[jj-1]==s[j])jj--;
    if(ii<jj&&ii-i+1+j-jj+1<3)GG;
    //printf("i=%d j=%d ii=%d jj=%d\n",i,j,ii,jj);
    if(ii>=jj){
      if(ii-jj+1>=2)printf("%d\n",ii-jj+2);
      else GG;
      return 0;
    }
    i=ii+1;j=jj-1;
  }


  return 0;
}