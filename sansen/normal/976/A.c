#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return -((int)*(char *)a-(int)*(char *)b);
}

void run(void){
  int n;
  scanf("%d",&n);
  char s[101];
  scanf("%s",s);
  if(n==1){
    printf("%s\n",s);
    return;
  }
  qsort(s,n,sizeof(char),cmp);
  int i=0;
  while(s[i+1]=='1') i++;
  while(i<n){
    putchar(s[i++]);
  }
  printf("\n");
  return;
}

int main(void){
  run();
  return 0;
}