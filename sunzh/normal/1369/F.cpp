#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int T;
int s[100010],e[100010];
int win[100010];
int lse[100010];
bool w(int st,int ed){
	if(ed&1) if(st&1) return 0;else return 1;
	if((st<<1)>ed){
		if(st&1) return 1;
		else return 0;
	}
	else if((st<<2)>ed) return 1;
	else return w(st,ed>>2);
}
bool l(int st,int ed){
	if((st<<1)>ed) return 1;
	return w(st,ed>>1);
}
signed main(){
	T=read();
	for(int i=1;i<=T;++i) s[i]=read(),e[i]=read();
	for(int i=1;i<=T;++i){
		win[i]=w(s[i],e[i]),lse[i]=l(s[i],e[i]);
	}
	bool f=1,v=0;
	for(int i=1;i<=T;++i){
		if(v==0&&f==0) break ;
		if(v==1&&f==1) break ;
		if(v==1&&f==0){
			f=lse[i]^1,v=win[i]^1;
		}
		else{
			v=win[i],f=lse[i];
		}
	}
	printf("%d %d\n",v,f);
	return 0;
}