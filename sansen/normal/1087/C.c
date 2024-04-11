#include<stdio.h>
#include<stdlib.h>

typedef struct point{
  int x,y;
} point;

void run(void){
  point p[3];
  int i;
  for(i=0;i<3;i++){
    scanf("%d%d",&p[i].x,&p[i].y);
  }
  point ans[4000];
  int len=0;
  while(1){
    int min=0;
    int max=0;
    for(i=1;i<3;i++){
      if(p[min].x>p[i].x) min=i;
      if(p[max].x<p[i].x) max=i;
    }
    if(min==max) break;
    if(p[min].x<p[3-max-min].x){
      ans[len++]=p[min];
      p[min].x++;
    } else {
      ans[len++]=p[max];
      p[max].x--;
    }
  }
  int x=p[0].x;
  int min=0;
  int max=0;
  for(i=1;i<3;i++){
    if(p[min].y>p[i].y) min=i;
    if(p[max].y<p[i].y) max=i;
  }
  for(i=p[min].y;i<=p[max].y;i++){
    ans[len++]=(point){x,i};
  }
  printf("%d\n",len);
  for(i=0;i<len;i++) printf("%d %d\n",ans[i].x,ans[i].y);
}

int main(void){
  run();
  return 0;
}