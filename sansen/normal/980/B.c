#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*(n+1)+(j))

void run(void){
  const int r=4;
  int n,k;
  scanf("%d%d",&n,&k);
  char board[801];
  int i,j;
  for(i=0;i<r;i++){
    for(j=0;j<n;j++){
      board[POS(i,j)]='.';
    }
    board[POS(i,n)]='\n';
  }
  board[POS(r,0)]='\0';

  if(k%2==0){
    for(i=1;2*i<=k;i++){
      board[POS(1,i)]='#';
      board[POS(2,i)]='#';
    }
    printf("YES\n");
    printf("%s",board);
    return;
  }

  int mid=n/2;
  int m=k/2;
  board[POS(1,mid)]='#';
  for(i=1;i<=MIN(m,(n-2)/2);i++){
    board[POS(1,mid+i)]='#';
    board[POS(1,mid-i)]='#';
  }

  if(k>n-2){
    k-=n-2;
    m=k/2;
    for(i=1;i<=m;i++){
      board[POS(2,mid+i)]='#';
      board[POS(2,mid-i)]='#';
    }
  }

  printf("YES\n");
  printf("%s",board);
  return;
}

int main(void){
  run();
  return 0;
}