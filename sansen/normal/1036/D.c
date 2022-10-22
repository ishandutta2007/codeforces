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
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int m;
  scanf("%d",&m);
  int *b=(int *)malloc(sizeof(int)*m);
  for(i=0;i<m;i++) scanf("%d",b+i);
  int ans=0;
  int64 s=a[0];
  int64 t=b[0];
  int j;
  i=j=1;
  while(i<n && j<m){
    while(i<n && s<t) s+=a[i++];
    while(j<m && t<s) t+=b[j++];
    if(s==t){
      ans++;
      s=t=0;
      if(i<n) s=a[i++];
      if(j<m) t=b[j++];
    }
  }
  while(i<n) s+=a[i++];
  while(j<m) t+=b[j++];
  if(s!=t){
    printf("-1\n");
    return;
  } else if(s>0){
    ans++;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}