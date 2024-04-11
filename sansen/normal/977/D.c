#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void scan(int64 *a){
  char s[20];
  scanf("%s",s);
  int64 res=0;
  int i=0;
  while(s[i]!='\0'){
    res=10*res+s[i]-'0';
    i++;
  }
  *a=res;
  return;
}

int cmp(const void *a,const void *b){
  int64 aa=*(int64 *)a;
  int64 bb=*(int64 *)b;
  if(aa==bb) return 0;
  return aa-bb<0?-1:1;
}

void swap(int64 *a,int64 *b){
  int64 t=*a;
  *a=*b;
  *b=t;
  return;
}

int count(int64 t){
  int c=0;
  while(t%3==0){
    t/=3;
    c++;
  }
  return c;
}

void run(void){
  int n;
  scanf("%d",&n);
  int64 a[100];
  int i;
  for(i=0;i<n;i++) scan(a+i);

  int k=0;
  while(k<n){
    int cnt=0;
    for(i=k;i<n;i++){
      int c=count(a[i]);
      if(cnt<c) cnt=c;
    }
    int l=k;
    int r=n-1;
    while(l<=r){
      int c=count(a[l]);
      if(c<cnt){
	swap(a+l,a+r);
	r--;
      } else {
	l++;
      }
    }

    if(l>k){
      qsort(a+k,l-k,sizeof(int64),cmp);
      k=l;
    } else {
      qsort(a+k,n-k,sizeof(int64),cmp);
      k=n;
    }
  }

  for(i=0;i<n;i++) printf("%lld ",a[i]);
  printf("\n");
  
  return;
}

int main(void){
  run();
  return 0;
}