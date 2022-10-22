#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n;
char s[110];
int sum;
int del[110];
void delt(int a){
	for(int i=a;i<=n;++i) s[i]=s[i+1];
	--n;
//	printf("n:%d\n",n);
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int j=25;j>=0;--j){
		int a=0;
		bool flag=0;
		do{
			flag=0;
			for(int i=1;i<=n;++i){
				if(s[i]=='a'+j){
					if(s[i-1]==s[i]-1||s[i+1]==s[i]-1){
						flag=1;
						a=i;
						break ;
					}
				}
			}
			if(flag){
				delt(a);
				++sum;
			}
		}while(flag); 
	}
	printf("%d\n",sum);
	return 0;
}