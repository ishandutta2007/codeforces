#include <cstdio>
#define Maxn 500000
char s[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	int begin=(1<<30),end=(-1<<30);
	for(int i=1;i<=n;i++){
		if(s[i]=='['){
			begin=mn(begin,i);
		}
		if(s[i]==']'){
			end=mx(end,i);
		}
	}
	if(begin==(1<<30)||end==(-1<<30)){
		puts("-1");
		return 0;
	}
	int ans=end-begin+1;
	int num=0;
	int start=(1<<30),fin=(-1<<30);
	for(int i=begin;i<=end;i++){
		if(s[i]==':'){
			num++;
			start=mn(start,i);
			fin=mx(fin,i);
		}
	}
	if(num<2){
		puts("-1");
		return 0;
	}
	ans=fin-start+3;
	for(int i=start+1;i<fin;i++){
		if(s[i]!='|'){
			ans--;
		}
	}
	printf("%d\n",ans);
	return 0;
}