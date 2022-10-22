#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int a,b,c,d;
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		if((a+b)&1){
			if(a||d){
				if(b||c) printf("Ya Ya Tidak Tidak\n");
				else printf("Ya Tidak Tidak Tidak\n");
			} 
			else printf("Tidak Ya Tidak Tidak\n");
		}
		else{
			if(a||d){
				if(b||c) printf("Tidak Tidak Ya Ya\n");
				else printf("Tidak Tidak Tidak Ya\n");
			} 
			else printf("Tidak Tidak Ya Tidak\n");
		}
	}
}