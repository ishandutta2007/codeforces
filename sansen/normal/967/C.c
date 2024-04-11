#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void solve(const int n,const int m,const int cl,const int ce,const int v,const int *ll,const int *e){
  int x,y,p,q;
  scanf("%d%d%d%d",&x,&y,&p,&q);
  if(x==p){
    printf("%d\n",ABS(y-q));
    return;
  }
  if(y>q){
    int swap=y;
    y=q;
    q=swap;
  }

  int min=n+2*m;

  if(cl>0){
    int l=0;
    int r=cl;
    while(l+1<r){
      int m=(l+r)/2;
      if(ll[m]>=y){
	r=m;
	} else {
	l=m;
      }
    }
    min=MIN(min,ABS(ll[l]-y)+ABS(x-p)+ABS(ll[l]-q));
    if(r<cl) min=MIN(min,ABS(ll[r]-y)+ABS(x-p)+ABS(ll[r]-q));
  }
  if(ce>0){
    int l=0;
    int r=ce;
    while(l+1<r){
      int m=(l+r)/2;
      if(e[m]>=y){
	r=m;
      } else {
	l=m;
      }
    }
    min=MIN(min,ABS(e[l]-y)+(ABS(x-p)+v-1)/v+ABS(e[l]-q));
    if(r<ce) min=MIN(min,ABS(e[r]-y)+(ABS(x-p)+v-1)/v+ABS(e[r]-q));
  }
  printf("%d\n",min);
  return;
}

void run(void){
  int n,m,cl,ce,v;
  scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
  int *l=(int *)malloc(sizeof(int)*(cl+1));
  int i;
  for(i=0;i<cl;i++) scanf("%d",l+i);
  int *e=(int *)malloc(sizeof(int)*(ce+1));
  for(i=0;i<ce;i++) scanf("%d",e+i);

  int q;
  scanf("%d",&q);
  while(q--){
    solve(n,m,cl,ce,v,l,e);
  }
  return;
}

int main(void){
  run();
  return 0;
}