#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  char *s=(char *)malloc(sizeof(char)*(n+1));
  scanf("%s",s);
  int cnt[256]={0};
  int i;
  for(i=0;i<n;i++) cnt[(int)s[i]]++;
  int max=cnt['A'];
  for(i='B';i<='A'+k-1;i++){
    max=MIN(max,cnt[i]);
  }
  printf("%d\n",max*k);
}

int main(void){
  run();
  return 0;
}