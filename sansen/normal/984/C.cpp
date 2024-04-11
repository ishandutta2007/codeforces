#include<stdio.h>

typedef long long int int64;

int64 gcd(int64 a,int64 b){
  int64 r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void run(void){
  int n;
  scanf("%d",&n);
  while(n--){
    int64 p,q,b;
    scanf("%lld%lld%lld",&p,&q,&b);
    int64 g=gcd(p,q);
    q/=g;
    g=gcd(q,b);
    while(g>1){
      q/=g;
      g=gcd(q,g);
    }
    printf("%s\n",q==1?"Finite":"Infinite");
  }
}

int main(void){
  run();
  return 0;
}