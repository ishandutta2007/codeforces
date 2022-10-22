#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int T;
int n;
char s[60];
char opt[60];
bool flag;
char st[7]={'a','b','a','c','a','b','a'};
void check(int x){
	for(int i=1;i<=n;++i){
		if(i==x) i+=7;
		if(opt[i]=='?') opt[i]='d';
	}
	int tot=0;
	for(int i=1;i+6<=n;++i){
		int j=0;
		for(j=0;j<7;++j){
			if(opt[i+j]!=st[j]) break ;
		}
		if(j==7) ++tot;
	}
	if(tot==1) {
		flag=1;
		printf("Yes\n");
		printf("%s\n",opt+1);
	}
}
int main(){
	T=read();
	while(T--){
		memset(opt,0,sizeof(opt));
		flag=0;
		n=read();
		scanf("%s",s+1);
		for(int i=1;i+6<=n;++i){
			for(int j=1;j<=n;++j)opt[j]=s[j];
			bool flag1=0;
			for(int j=0;j<7;++j){
				if(s[i+j]!=st[j]&&s[i+j]!='?'){
					flag1=1;break ;
				}
				if(s[i+j]=='?') opt[i+j]=st[j];
			}
			if(flag1) continue ;
			check(i);
			if(flag) break ; 
		}
		if(!flag) printf("No\n");
	}
	return 0;
}