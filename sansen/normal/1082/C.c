#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct binaryHeap{
  void *h;
  int heapSize;
  int maxSize;
  size_t size;
  int (*cmp)(const void *,const void *);
} heap;

heap* newHeap(const size_t size,int (*cmpF)(const void *,const void *)){
  const int maxSize=1;
  heap *res=(heap *)malloc(sizeof(heap));
  res->h=malloc(size*(maxSize+1));
  res->heapSize=0;
  res->maxSize=maxSize;
  res->size=size;
  res->cmp=cmpF;
  return res;
}

int isEmpty(const heap *h){
  return h->heapSize==0;
}

void freeHeap(heap *h){
  free(h->h);
  free(h);
  return;
}

void initHeap(heap *h){
  h->heapSize=0;
  return;
}

inline void heapFunc_swap(void * restrict a,void * restrict b,void * restrict tmp,size_t size){
  memcpy(tmp,a,size);
  memcpy(a,b,size);
  memcpy(b,tmp,size);
  return;
}

void push(heap *q,const void *p){
  if(q->heapSize==q->maxSize){
    q->h=realloc(q->h,q->size*(2*q->maxSize+1));
    q->maxSize*=2;
  }
  q->heapSize+=1;
  void *h=q->h;
  int k=q->heapSize;
  size_t size=q->size;
  int (*cmp)(const void *,const void *)=q->cmp;
  memcpy(h+k*size,p,size);
  while(k>1){
    if(cmp(h+(k/2)*size,h+k*size)<=0) return;
    heapFunc_swap(h+(k/2)*size,h+k*size,h,size);
    k/=2;
  }
  return;
}

void pop(heap *q,void *res){
  void *h=q->h;
  size_t size=q->size;
  if(res!=NULL) memcpy(res,h+size,size);
  memcpy(h+size,h+size*q->heapSize,size);
  q->heapSize-=1;
  int (*cmp)(const void *,const void *)=q->cmp;
  int n=q->heapSize;
  int k=1;
  while(2*k+1<=n){
    int next=cmp(h+2*k*size,h+(2*k+1)*size)<=0?2*k:2*k+1;
    if(cmp(h+k*size,h+next*size)<=0) return;
    heapFunc_swap(h+k*size,h+next*size,h,size);
    k=next;
  }
  if(2*k<=n && cmp(h+k*size,h+2*k*size)>0) heapFunc_swap(h+k*size,h+2*k*size,h,size);
  return;
}

void top(const heap *q,void *res){
  memcpy(res,q->h+q->size,q->size);
  return;
}

#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(const void *a,const void *b){
  return *(int *)b-*(int *)a;
}

typedef long long int int64;

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  heap **h=(heap **)calloc(m+1,sizeof(heap *));
  int i;
  for(i=0;i<=m;i++) h[i]=newHeap(sizeof(int),cmp);
  for(i=0;i<n;i++){
    int s,r;
    scanf("%d%d",&s,&r);
    push(h[s],&r);
  }
  int64 *sum=(int64 *)calloc(m+1,sizeof(int64));
  int64 max=0;
  int len=0;
  for(i=0;i<=m;i++) if(!isEmpty(h[i])) h[len++]=h[i];
  while(len>0){
    int64 local=0;
    for(i=0;i<len;i++){
      int v;
      pop(h[i],&v);
      sum[i]+=v;
      if(sum[i]>0) local+=sum[i];
    }
    max=MAX(max,local);
    int j=0;
    for(i=0;i<len;i++){
      if(!isEmpty(h[i]) && sum[i]>0){
	h[j]=h[i];
	sum[j]=sum[i];
	j++;
      }
    }
    len=j;
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
}