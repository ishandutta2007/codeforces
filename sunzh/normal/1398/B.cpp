#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
char s[110];
int cnt;
int opt[110];
int main(){
	T=read();
	while(T--){
		cnt=0;
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;++i){
			int num=0;
			if(s[i]=='0') continue ;
			while(i+num<=len&&s[i+num]=='1') ++num;
			opt[++cnt]=num;
			i=i+num;
		}
		int ans=0;
		sort(opt+1,opt+cnt+1);
		for(int i=cnt;i>=1;i-=2){
			ans+=opt[i];
		}
		printf("%d\n",ans);
	}
}