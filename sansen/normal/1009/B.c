#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run(void){
  char *s=(char *)calloc(100000+1,sizeof(char));
  scanf("%s",s);
  int n=strlen(s);
  int cnt=0;
  int i;
  for(i=0;i<n;i++) cnt+=s[i]=='1'?1:0;
  for(i=0;i<n && s[i]!='2';i++) if(s[i]=='0') putchar('0');
  while(cnt--) putchar('1');
  for(;i<n;i++) if(s[i]!='1') putchar(s[i]);
  putchar('\n');
  return;
}

int main(void){
  run();
  return 0;
}