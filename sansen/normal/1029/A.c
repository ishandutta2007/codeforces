#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int eq(char *s,char *t,int n){
  int i=0;
  for(i=0;i<n;i++) if(s[i]!=t[i]) return 0;
  return 1;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  char t[51];
  scanf("%s",t);
  int i;
  for(i=1;i<n;i++){
    if(eq(t,t+i,n-i)) break;
  }
  if(i<n){
    printf("%s",t);
    int j;
    for(j=1;j<k;j++){
      printf("%s",t+n-i);
    }
    printf("\n");
  } else {
    for(i=0;i<k;i++) printf("%s",t);
    printf("\n");
  }
  return;
}

int main(void){
  run();
  return 0;
}