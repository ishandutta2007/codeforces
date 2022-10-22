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
int n,m,a,b;
int main(){
	n=read(),m=read(),a=read(),b=read();
	if(m==1){
		printf("%d\n",1);
	}
	else{
		int f1=(a+m-1)/m,f2=(b+m-1)/m;
		if(f1==f2) printf("1\n");
		else if(f2-f1==1){
			if(a%m==1&&(b%m==0||b==n)) printf("1\n");
			else printf("2\n");
		}
		else{
			if(a%m==1){
				if(b%m==0||b==n) printf("1\n");
				else printf("2\n");
			}
			else{
				if(b%m==0||b==n||(a%m==0?m:a%m)-1==(b%m==0?n:b%m)) printf("2\n");
				else printf("3\n");
			}
		}
	}
	return 0;
}