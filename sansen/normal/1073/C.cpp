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
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  int x,y;
  scanf("%d%d",&x,&y);
  if(ABS(x)+ABS(y)>n || n%2!=(ABS(x)+ABS(y))%2){
    printf("-1\n");
    return;
  }
  int *px=(int *)calloc(n+1,sizeof(int));
  int *py=(int *)calloc(n+1,sizeof(int));
  int i;
  for(i=1;i<=n;i++){
    px[i]=px[i-1];
    py[i]=py[i-1];
    const char op=s[i-1];
    if(op=='U'){
      py[i]=py[i-1]+1;
    } else if(op=='D'){
      py[i]=py[i-1]-1;
    } else if(op=='L'){
      px[i]=px[i-1]-1;
    } else {
      px[i]=px[i-1]+1;
    }
  }
  if(px[n]==x && py[n]==y){
    printf("0\n");
    return;
  }
  int min=n;
  int p=0;
  for(i=0;i<n;i++){
    int xx=x-px[i];
    int yy=y-py[i];
    while(p<=n && ABS(px[n]-xx-px[p])+ABS(py[n]-py[p]-yy)>p-i){
      p++;
    }
    if(p>n) break;
    min=MIN(min,p-i);
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
}