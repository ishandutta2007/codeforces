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
  char *s=(char *)malloc(sizeof(char)*(n+1));
  scanf("%s",s);
  int cnt[26];
  int i;
  for(i=0;i<26;i++) cnt[i]=0;
  for(i=0;i<n;i++) cnt[s[i]-'a']++;
  if(n==1){
    printf("Yes\n");
    return;
  }
  for(i=0;i<26;i++){
    if(cnt[i]>=2){
      printf("Yes\n");
      return;
    }    
  }
  printf("No\n");
  return;
}

int main(void){
  run();
  return 0;
}