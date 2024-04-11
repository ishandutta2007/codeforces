#include<stdio.h>
#include<string.h>

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    char s[1001];
    scanf("%s",s);
    int n=strlen(s);
    int i;
    for(i=1;i<n;i++){
      if(s[i]!=s[0]){
	char c=s[n-1];
	s[n-1]=s[i];
	s[i]=c;
	break;
      }
    }
    if(i<n){
      printf("%s\n",s);
    } else {
      printf("-1\n");
    }
  }
}

int main(void){
  run();
  return 0;
}