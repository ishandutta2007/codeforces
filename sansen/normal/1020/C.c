#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*n+(j))

const int64 inf=1000000000LL*3001;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int64 calc(int k,int *pp,int *plen,int n,int m){
  int begin[3001]={0};
  int64 res=0;
  int cnt=plen[1];
  int i;
  for(i=2;i<=m;i++){
    int j;
    for(j=0;plen[i]-j>=k;j++){
      res+=pp[POS(i,j)];
      cnt++;
    }
    begin[i]=j;
  }
  if(cnt>k) return inf;
  int array[3000];
  int len=0;
  for(i=2;i<=m;i++){
    int j;
    for(j=begin[i];j<plen[i];j++){
      array[len++]=pp[POS(i,j)];
    }
  }
  qsort(array,len,sizeof(int),cmp);
  for(i=0;i<len && cnt<k;i++,cnt++){
    res+=array[i];
  }
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int p[3001];
  int c[3001];
  int i;
  for(i=1;i<=n;i++) scanf("%d%d",p+i,c+i);
  int *pp=(int *)malloc(sizeof(int)*(m+1)*n);
  int *plen=(int *)calloc(m+1,sizeof(int));
  for(i=1;i<=n;i++){
    int index=p[i];
    pp[POS(index,plen[index]++)]=c[i];
  }
  for(i=1;i<=m;i++){
    if(plen[i]>=1){
      qsort(pp+POS(i,0),plen[i],sizeof(int),cmp);
    }
  }
  int64 ans=calc(plen[1],pp,plen,n,m);
  for(i=plen[1]+1;i<=n;i++){
    int64 t=calc(i,pp,plen,n,m);
    ans=MIN(ans,t);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}