#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void msort(void *a,const size_t n,const size_t size,int (*cmp)(const void *,const void *)){
  void *tmp=malloc(size*n);
  typedef struct {
    size_t l,r;
    int op;
  } OP;
  OP s[64];
  int top=0;
  s[top++]=(OP){0,n,0};
  while(top>0){
    OP t=s[--top];
    if(t.r-t.l<=1) continue;
    size_t m=(t.l+t.r)/2;
    if(t.op==0){
      s[top++]=(OP){t.l,t.r,1};
      s[top++]=(OP){t.l,  m,0};
      s[top++]=(OP){  m,t.r,0};
    } else {
      size_t i=t.l,j=m,k=0;
      while(i<m && j<t.r){
	if(cmp(a+i*size,a+j*size)<=0){
	  memcpy(tmp+k*size,a+i*size,size);
	  i++;k++;
	} else {
	  memcpy(tmp+k*size,a+j*size,size);
	  j++;k++;
	}
      }
      if(i<m) memcpy(tmp+k*size,a+i*size,(m-i)*size);
      memcpy(a+t.l*size,tmp,(j-t.l)*size);
    }
  }
  free(tmp);
  return;
}

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int t;
  scanf("%d",&t);
  int *a=(int *)malloc(sizeof(int)*1000000);
  int *b=(int *)calloc(20000,sizeof(int));
  int *cnt=(int *)calloc(10000+1,sizeof(int));
  while(t--){
    int n;
    scanf("%d",&n);
    int len=0;
    int i;
    for(i=0;i<n;i++){
      scanf("%d",a+i);
      cnt[a[i]]++;
      if(cnt[a[i]]==2) b[len++]=a[i];
      if(cnt[a[i]]==4) b[len++]=a[i];
    }
    msort(b,len,sizeof(int),cmp);
    int min=0;
    for(i=1;i+1<len;i++){
      if(b[min+1]*b[i]>b[i+1]*b[min]) min=i;
    }
    printf("%d %d %d %d\n",b[min],b[min],b[min+1],b[min+1]);
    for(i=0;i<n;i++) cnt[a[i]]--;
  }
}

int main(void){
  run();
  return 0;
}