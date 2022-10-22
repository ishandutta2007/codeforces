#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*n+(j))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  char board[10001];
  int i,j;
  for(i=0;i<n;i++){
    scanf("%s",board+POS(i,0));
  }
  int *cnt=(int *)calloc(n*n,sizeof(int));

  //row
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      int l;
      for(l=j;l<n && l<j+k;l++){
	if(board[POS(i,l)]=='#') break;
      }
      if(l==j+k){
	//printf("row %d %d\n",i,j);
	for(l=j;l<j+k;l++){
	  cnt[POS(i,l)]++;
	}
      }
    }
  }

  //row
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      int l;
      for(l=i;l<n && l<i+k;l++){
	if(board[POS(l,j)]=='#') break;
      }
      if(l==i+k){
	//printf("col %d %d\n",i,j);
	for(l=i;l<i+k;l++){
	  cnt[POS(l,j)]++;
	}
      }
    }
  }

  int max=0;
  int x=0;
  int y=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(cnt[POS(i,j)]>max){
	max=cnt[POS(i,j)];
	x=i;
	y=j;
      }
    }
  }
  /*
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(cnt[POS(i,j)]==max){
	//printf("%d %d\n",i+1,j+1);
      }
    }
  }
  */
  printf("%d %d\n",x+1,y+1);
}

int main(void){
  run();
  return 0;
}