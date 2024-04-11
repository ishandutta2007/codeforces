#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*m+(j))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  char *s=(char *)malloc(sizeof(char)*(n*m+1));
  int i,j;
  for(i=0;i<n;i++) scanf("%s",s+POS(i,0));
  for(i=1;i+1<n;i++){
    for(j=1;j+1<m;j++){
      int dx[]={1,1,0,-1,-1,-1,0,1};
      int dy[]={0,-1,-1,-1,0,1,1,1};
      int k;
      for(k=0;k<8;k++) if(s[POS(i+dx[k],j+dy[k])]=='.') break;
      if(k==8){
	for(k=0;k<8;k++) s[POS(i+dx[k],j+dy[k])]='?';
      }
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(s[POS(i,j)]=='#'){
	printf("NO\n");
	return;
      }
    }
  }
  printf("YES\n");
}

int main(void){
  run();
  return 0;
}