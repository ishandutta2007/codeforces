#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<cmath> 
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,k;
int cnt;
int a[110];
int main(){
	T=read();
	while(T--){
		cnt=0;n=read(),k=read();
		a[0]=-1;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]!=a[i-1]) ++cnt;
		}
		if(cnt>1&&k==1) printf("-1\n");
		else if(k==1) printf("1\n");
		else{
			printf("%d\n",max(1,(int)ceil(1.0*(cnt-1.0)/(k-1.0))));
		}
	}
}