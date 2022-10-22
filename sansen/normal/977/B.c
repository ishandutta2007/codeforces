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
  char s[101];
  scanf("%s",s);
  char ans[3];
  ans[2]='\0';
  int max=0;
  int i;
  for(i=0;i+1<n;i++){
    char a=s[i];
    char b=s[i+1];
    int cnt=0;
    int j;
    for(j=0;j+1<n;j++){
      if(s[j]==a && s[j+1]==b) cnt++;
    }
    if(cnt>max){
      ans[0]=a;
      ans[1]=b;
      max=cnt;
    }
  }
  printf("%s\n",ans);
  return;
}

int main(void){
  run();
  return 0;
}