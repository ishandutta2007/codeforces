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
int tag;
char str1[100010],str2[100010];
int ans[300010];
int cnt;
inline char change(char x){
	if(tag) return x=='1'?'0':'1';
	else return x;
}
int main(){
	T=read();
	while(T--){
		cnt=tag=0;
		n=read();
		scanf("%s",str1+1);
		scanf("%s",str2+1);
		int l=1,r=n,tmp;
		for(int i=n;i>=1;--i){
			if(l<=r){
				if(change(str1[r])==str2[i]){
					--r; continue ;
				}
				else{
					if(change(str1[l])==str2[i]) ans[++cnt]=1;
					ans[++cnt]=i;
					tmp=r;r=l+1;l=tmp;tag^=1;
				}
			}
			else{
				if(change(str1[r])==str2[i]){
					++r;continue ;
				}
				else{
					if(change(str1[l])==str2[i]) ans[++cnt]=1;
					ans[++cnt]=i;
					tmp=r;r=l-1;l=tmp;tag^=1;
				}
			}
		}
		printf("%d ",cnt);
		for(int i=1;i<=cnt;++i) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}