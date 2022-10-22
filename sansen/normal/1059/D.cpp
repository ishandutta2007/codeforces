#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

float calc(float rad,float *x,float *y,int n){
  if(2*rad<y[0]) return 0;
  float l=x[0]-sqrtf(y[0]*(2*rad-y[0]));
  float r=x[0]+sqrtf(y[0]*(2*rad-y[0]));
  int i;
  for(i=1;i<n;i++){
    if(2*rad<y[i]) return 0;
    float ll=x[i]-sqrtf(y[i]*(2*rad-y[i]));
    float rr=x[i]+sqrtf(y[i]*(2*rad-y[i]));
    l=MAX(l,ll);
    r=MIN(r,rr);
  }
  return l<=r;
}

void run(void){
  int n;
  scanf("%d",&n);
  float *x=(float *)malloc(sizeof(float)*n);
  float *y=(float *)malloc(sizeof(float)*n);
  int i;
  for(i=0;i<n;i++) scanf("%f%f",x+i,y+i);
  int sign=y[0]>0?1:-1;
  y[0]*=sign;
  for(i=1;i<n;i++){
    y[i]*=sign;
    if(y[i]<0){
      printf("-1\n");
      return;
    }
  }
  float l=0;
  float r=1e18;
  for(i=0;i<100;i++){
    float m=(l+r)/2;
    if(calc(m,x,y,n)){
      r=m;
    } else {
      l=m;
    }
  }
  float ans=(l+r)/2;
  printf("%.6f\n",ans);
}

int main(void){
  run();
  return 0;
}