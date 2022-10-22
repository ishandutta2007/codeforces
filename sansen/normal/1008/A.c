#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char s[101];
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  int c[]={'a','i','u','e','o'};
  int i;
  for(i=0;i<n;i++){
    int j;
    for(j=0;j<5;j++) if(s[i]==c[j]) break;
    if(j<5) continue;
    if(s[i]=='n') continue;
    if(i+1<n){
      for(j=0;j<5;j++) if(s[i+1]==c[j]) break;
      if(j<5) continue;
    }
    printf("NO\n");
    return;
  }
  printf("YES\n");
  return;
}

int main(void){
  run();
  return 0;
}