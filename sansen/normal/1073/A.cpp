#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  char s[1001];
  scanf("%s",s);
  int i;
  for(i=0;i+1<n;i++){
    if(s[i]!=s[i+1]){
      printf("YES\n%c%c\n",s[i],s[i+1]);
      return;
    }
  }
  printf("NO\n");
}

int main(void){
  run();
  return 0;
}