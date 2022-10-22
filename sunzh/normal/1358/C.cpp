#include<iostream>
#include<cstdio>
using namespace std;
int inline read(){
	int num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*neg;
}
int n;
int x1,y1,x2,y2;
long long ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		x1=read(),y1=read(),x2=read(),y2=read();
		ans=1ll*(x2-x1)*(y2-y1)+1;
		printf("%lld\n",ans); 
	}
	return 0;
}