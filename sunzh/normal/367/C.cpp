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
int n,m;
int q[100010],w[100010];
bool cmp(int x,int y){
	return x>y;
}
int func(int x){
	int res=x*(x-1)>>1;
	if(x&1) ++res;else res+=x>>1;
	return res;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		q[i]=read(),w[i]=read();
	}
	sort(w+1,w+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=m;++i){
		if(func(i)>n) break ;
		ans+=w[i];
	}
	printf("%lld\n",ans);
	return 0;
}