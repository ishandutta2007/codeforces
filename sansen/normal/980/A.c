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
  int len=0;
  while(s[len]!='\0') len++;

  int p=0;
  int l=0;
  int i;
  for(i=0;i<len;i++){
    if(s[i]=='-'){
      l++;
    } else {
      p++;
    }
  }
  if(l==0 || p==0 || l%p==0){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main(void){
  run();
  return 0;
}