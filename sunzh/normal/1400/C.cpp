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
int x;
char s[100010];
bool vis[100010];
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);x=read();
		int len=strlen(s+1);
		for(int i=1;i<=len;++i) vis[i]=0;
		for(int i=1;i<=len;++i){
			if(s[i]=='0'){
				if(i-x>0) vis[i-x]=1;
				if(i+x<=len) vis[i+x]=1;
			}
		}
		bool flag=0;
		for(int i=1;i<=len;++i){
			if(s[i]=='1'){
				int c=0;
				if(i-x>0) c+=(!vis[i-x]);
				if(i+x<=len) c+=(!vis[i+x]);
				if(!c) flag=1;
			}
		}
		if(flag) printf("-1\n");
		else{
			for(int i=1;i<=len;++i) putchar((vis[i]?'0':'1'));
			putchar('\n');
		}
	}
	return 0;
}