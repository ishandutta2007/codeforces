#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int uint64;

int cmp(const void *a,const void *b){
  uint64 p=*(uint64 *)a;
  uint64 q=*(uint64 *)b;
  return p==q?0:p<q?-1:1;
}

uint64 *array=NULL;
int len=0;
void init(void){
  array=(uint64 *)malloc(sizeof(uint64)*10*10*10*816);
  uint64 d[19];
  d[0]=1;
  int i;
  for(i=1;i<=18;i++) d[i]=10*d[i-1];
  len=0;
  int j,k,l,m,n;
  for(i=1;i<=9;i++){
    for(j=0;j<=18;j++){
      array[len++]=d[j]*i;
    }
  }
  for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
      for(l=0;l<=18;l++){
	for(m=l+1;m<=18;m++){
	  array[len++]=i*d[l]+j*d[m];
	}
      }
    }
  }
  for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
      for(k=1;k<=9;k++){
	for(l=0;l<=18;l++){
	  for(m=l+1;m<=18;m++){
	    for(n=m+1;n<=18;n++){
	      array[len++]=i*d[l]+j*d[m]+k*d[n];
	    }
	  }
	}
      }
    }
  }
  qsort(array,len,sizeof(uint64),cmp);
  return;
}

int count(uint64 n){
  if(n==0) return 0;
  int l=0;
  int r=len;
  while(r-l>1){
    int m=(l+r)/2;
    if(array[m]<=n){
      l=m;
    } else {
      r=m;
    }
  }
  return l+1;
}

void run(void){
  init();
  int t;
  scanf("%d",&t);
  while(t--){
    uint64 l,r;
    scanf("%llu%llu",&l,&r);
    int ans=count(r)-count(l-1);
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
}