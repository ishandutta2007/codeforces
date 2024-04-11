#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef long long int int64;

static void printInt(int64 n){
  if(n<0){putchar('-');n=-n;}
  if(n==0){putchar('0');return;}
  int s[20];int len=0;
  while(n>0){s[len++]=n%10+'0';n/=10;}
  while(len>0){putchar(s[--len]);}
}
static int64 readInt(void){
  int prev='\0';int c=getchar();
  while(!('0'<=c && c<='9')){prev=c;c=getchar();}
  int64 res=0;
  while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}
  return prev=='-'?-res:res;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*(n+1)+(j))

void run(void){
  const int m=10000;
  char *t=(char *)calloc(m+10,sizeof(char));
  scanf("%s",t);
  const int n=strlen(t);
  char *query=(char *)calloc(3*(n+1),sizeof(char));
  const int f=26;
  int i;
  for(i=0;i<n;i++){
    query[POS(0,i)]='a'+i/f/f;
    query[POS(1,i)]='a'+i/f%f;
    query[POS(2,i)]='a'+i%f;
  }
  char *ans=(char *)calloc(3*(n+1),sizeof(char));
  for(i=0;i<3;i++){
    printf("? %s\n",query+POS(i,0));
    fflush(stdout);
    scanf("%s",ans+POS(i,0));
  }
  int *index=(int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++){
    int k=(ans[POS(0,i)]-'a')*f*f+(ans[POS(1,i)]-'a')*f+(ans[POS(2,i)]-'a');
    index[i]=k;
  }
  char *s=(char *)calloc(n+1,sizeof(char));
  for(i=0;i<n;i++){
    s[index[i]]=t[i];
  }
  printf("! %s\n",s);
  return;
}

int main(void){
  run();
  return 0;
}