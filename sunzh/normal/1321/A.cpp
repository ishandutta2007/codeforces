#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int m1,m2; 
int n;
int p1[110],p2[110];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p1[i]=read();
	}
	for(int i=1;i<=n;++i) p2[i]=read();
	for(int i=1;i<=n;++i){
		if(p1[i]!=p2[i]){
			if(p1[i]) m1++;
			else m2++;
		}
	}
	if(m1==0&&m2>=0){
		printf("-1");
		return 0;
	}
	if(m1>m2){
		printf("1");
		return 0;
	}
	int ans=(m2/m1)+1;
	printf("%d\n",ans);
	return 0;
}