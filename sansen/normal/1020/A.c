#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,h,a,b,k;
  scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
  int i;
  for(i=0;i<k;i++){
    int p,q,r,s;
    scanf("%d%d%d%d",&p,&q,&r,&s);
    if(p==r){
      printf("%d\n",ABS(q-s));
    } else if((a<=q && q<=b) || (a<=s && s<=b)){
      printf("%d\n",ABS(q-s)+ABS(p-r));
    } else {
      int aa=ABS(p-r)+ABS(q-a)+ABS(s-a);
      int bb=ABS(p-r)+ABS(q-b)+ABS(s-b);
      printf("%d\n",MIN(aa,bb));
    }
  }
}

int main(void){
  run();
  return 0;
}