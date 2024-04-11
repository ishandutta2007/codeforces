#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int T;
char s[200010];
int num[3];
int main(){
	T=read();
	while(T--){
		int len=0;
		memset(num,0,sizeof(num));
		char c=getchar();
		while(c<'A'||c>'Z') c=getchar();
		while(c=='R'||c=='S'||c=='P'){
			s[++len]=c;
			c=getchar();
		}
		for(int i=1;i<=len;++i){
			if(s[i]=='R') ++num[0];
			if(s[i]=='S') ++num[1];
			if(s[i]=='P') ++num[2];
		}
		int maxn=max(num[0],max(num[1],num[2]));
		if(maxn==num[0]){
			for(int i=1;i<=len;++i) putchar('P');
			putchar('\n');
		}
		else if(maxn==num[1]){
			for(int i=1;i<=len;++i) putchar('R');
			putchar('\n');
		}
		else{
			for(int i=1;i<=len;++i) putchar('S');
			putchar('\n');
		}
	}
	return 0;
}