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
  char *s=(char *)malloc(sizeof(char)*(100000+1));
  int cnt[3]={0,0,0};
  int i;
  for(i=0;i<3;i++){
    scanf("%s",s);
    int c[256]={0};
    int len;
    for(len=0;s[len]!='\0';len++){
      c[(int)s[len]]++;
    }
    int max=0;
    int j;
    for(j=0;j<256;j++) max=MAX(max,c[j]);
    if(n==1 && max==len){
      cnt[i]=len-1;
    } else {
      cnt[i]=MIN(max+n,len);
    }
  }
  int max=0;
  for(i=0;i<3;i++) max=MAX(cnt[i],max);
  int c=0;
  for(i=0;i<3;i++){
    if(cnt[i]==max) c++;
  }
  if(c>1){
    printf("Draw\n");
  } else if(cnt[0]==max){
    printf("Kuro\n");
  } else if(cnt[1]==max){
    printf("Shiro\n");
  } else {
    printf("Katie\n");
  }
}

int main(void){
  run();
  return 0;
}