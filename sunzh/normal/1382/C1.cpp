#include<iostream>
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
int n;
char str1[1010],str2[1010];
int ans[3010];
int cnt;
int main(){
	T=read();
	while(T--){
		cnt=0;
		n=read();
		scanf("%s",str1+1);
		scanf("%s",str2+1);
		for(int i=1;i<=n;++i){
			if(str1[i]!=str2[i]){
				ans[++cnt]=i;
				ans[++cnt]=1;
				ans[++cnt]=i;
			}
		}
		printf("%d ",cnt);
		for(int i=1;i<=cnt;++i) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}