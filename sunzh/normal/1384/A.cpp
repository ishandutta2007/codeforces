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
int n;
int a[210];
char s[210][210];
int main() {
	T=read();
	while(T--){
		memset(s,0,sizeof(s));
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		a[n+1]=0;
		s[0][1]='a'-1;
		for(int i=1;i<=n+1;++i){
			int len=max(a[i-1],a[i]);
			if(len==0){
				s[i][1]=(s[i-1][1]=='z'?'a':s[i-1][1]+1);
			}
			else{
				for(int j=1;j<=a[i-1];++j) s[i][j]=s[i-1][j];
				for(int j=a[i-1]+1;j<=len;++j) if(s[i-1][j]) s[i][j]=(s[i-1][j]=='z'?'a':s[i-1][j]+1);else s[i][j]='a';
			}
		}
		for(int i=1;i<=n+1;++i) printf("%s\n",s[i]+1);
	}
}