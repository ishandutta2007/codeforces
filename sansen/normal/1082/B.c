#include<stdio.h>
#include<stdlib.h>

int can(int m,char *s,int n){
  int local=0;
  int i;
  for(i=0;i<m;i++) if(s[i]=='G') local++;
  if(local>=m-1) return 1;
  for(;i<n;i++){
    if(s[i-m]=='G') local--;
    if(s[i]=='G') local++;
    if(local>=m-1) return 1;
  }
  return 0;
}

void run(void){
  int n;
  scanf("%d",&n);
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  int sum=0;
  int i;
  for(i=0;i<n;i++) if(s[i]=='G') sum++;
  int l=0;
  int r=sum+1;
  while(r-l>1){
    int m=(l+r)/2;
    if(can(m,s,n)){
      l=m;
    } else {
      r=m;
    }
  }
  printf("%d\n",l);  
}

int main(void){
  run();
  return 0;
}