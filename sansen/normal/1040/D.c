#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int64 n;
  int k;
  scanf("%lld%d",&n,&k);
  srand((unsigned)time(NULL));
  int64 l=1;
  int64 r=n;
  while(1){
    while(r-l+1>5*k+1){
      int64 m=(l+r)/2;
      printf("%lld %lld\n",l,m);
      fflush(stdout);
      char ans[10];
      scanf("%s",ans);
      if(ans[0]=='Y'){
	l=MAX(l-k,1);
	r=MIN(m+k,n);
      } else if(ans[0]=='N'){
	l=MAX(m+1-k,1);
	r=MIN(r+k,n);
      } else {
	exit(1);
      }
    }
    int64 m=rand()%(r-l+1)+l;
    printf("%lld %lld\n",m,m);
    fflush(stdout);
    char ans[10];
    scanf("%s",ans);
    if(ans[0]=='Y'){
      return;
    } else {
      l=MAX(l-k,1);
      r=MIN(r+k,n);
    }
  }
}

int main(void){
  run();
  return 0;
}