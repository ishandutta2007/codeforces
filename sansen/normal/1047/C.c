#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  scanf("%d",a);
  int g=a[0];
  int i,j;
  for(i=1;i<n;i++){
    scanf("%d",a+i);
    g=gcd(g,a[i]);
  }
  for(i=0;i<n;i++) a[i]/=g;
  const int m=15000000;
  int *f=(int *)malloc(sizeof(int)*(m+1));
  for(i=0;i<=m;i++) f[i]=i;
  for(i=2;i*i<=m;i++) if(f[i]==i) for(j=i*i;j<=m;j+=i) f[j]=i;
  int *cnt=(int *)calloc(m+1,sizeof(int));
  for(i=0;i<n;i++){
    int t=a[i];
    while(t>1){
      int p=f[t];
      cnt[p]++;
      while(t%p==0) t/=p;
    }
  }
  int max=0;
  for(i=2;i<=m;i++) max=MAX(max,cnt[i]);
  printf("%d\n",max==0?-1:n-max);
}

int main(void){
  run();
  return 0;
}