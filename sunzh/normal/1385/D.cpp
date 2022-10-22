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
char s[200010];
int dfs(int l,int r,int x){
	if(l>r) return 0;
	if(l==r) return s[l]!='a'+x;
	int mid=l+r>>1;
	int res1=0,res2=0;
	for(int i=l;i<=mid;++i) if(s[i]!='a'+x) ++res1;
	res1=res1+dfs(mid+1,r,x+1);
	for(int i=mid+1;i<=r;++i) if(s[i]!='a'+x) ++res2;
	res2=res2+dfs(l,mid,x+1);
	return min(res1,res2);
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		printf("%d\n",dfs(1,n,0)); 
	}
	return 0;
}