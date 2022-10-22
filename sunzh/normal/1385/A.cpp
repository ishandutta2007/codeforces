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
int t;
int x,y,z;
int main(){
	t=read();
	while(t--){
		x=read(),y=read(),z=read();
		int a,b,c;
		if(x==y){
			if(x>=z){
				printf("YES\n%d %d %d\n",x,z,1); 
			}
			else printf("NO\n");
		}
		else if(x>y){
			if(x==z) printf("YES\n%d %d %d\n",y,x,1);
			else printf("NO\n");
		}
		else if(x<y){
			if(y==z) printf("YES\n%d %d %d\n",x,1,y);
			else printf("NO\n");
		}
	}
	return 0;
}