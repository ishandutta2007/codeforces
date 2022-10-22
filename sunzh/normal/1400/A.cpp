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
char s[110];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=(n<<1);i+=2){
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}