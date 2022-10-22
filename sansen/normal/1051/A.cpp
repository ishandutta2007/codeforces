#include<stdio.h>
#include<string.h>

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    char s[101];
    scanf("%s",s);
    int n=strlen(s);
    int cnt[3]={0,0,0};
    int i;
    for(i=0;i<n;i++){
      if('a'<=s[i] && s[i]<='z'){
	cnt[0]++;
      } else if('A'<=s[i] && s[i]<='Z'){
	cnt[1]++;
      } else {
	cnt[2]++;
      }
    }
    if(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
      printf("%s\n",s);
    } else if(cnt[0]==0 && cnt[1]==0){
      s[0]='a';
      s[1]='A';
      printf("%s\n",s);
    } else if(cnt[0]==0 && cnt[2]==0){
      s[0]='a';
      s[1]='0';
      printf("%s\n",s);
    } else if(cnt[1]==0 && cnt[2]==0){
      s[0]='A';
      s[1]='0';
      printf("%s\n",s);
    } else {
      char c=cnt[0]==0?'a':cnt[1]==0?'A':'0';
      int b=cnt[0]<cnt[1]?cnt[1]<cnt[2]?2:1:cnt[0]<cnt[2]?2:0;
      int l=b==0?'a':b==1?'A':'0';
      int r=b==0?'z':b==1?'Z':'9';
      for(i=0;i<n;i++){
	if(l<=s[i] && s[i]<=r){
	  s[i]=c;
	  break;
	}
      }
      printf("%s\n",s);
    }
  }
}

int main(void){
  run();
  return 0;
}