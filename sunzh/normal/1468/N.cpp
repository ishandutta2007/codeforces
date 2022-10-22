#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int c[30],a[50];
int main(){
	T=read();
	while(T--){
//		printf("T:%d\n",T);
		for(int i=1;i<=3;++i) c[i]=read();
		for(int i=1;i<=5;++i) a[i]=read();
		for(int i=1;i<=3;++i) c[i]-=a[i];
		if(c[1]>a[4]) c[1]-=a[4];
		else{
			a[4]-=c[1];c[3]-=a[4];
		}
		if(c[2]>a[5]) c[2]-=a[5];
		else{
			a[5]-=c[2];c[3]-=a[5];
		}
		bool f=0;
		for(int i=1;i<=3;++i) if(c[i]<0) f=1;
		if(f) printf("NO\n");
		else printf("YES\n");
	}
}