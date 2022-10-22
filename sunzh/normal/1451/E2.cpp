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
#define pow powl
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int pos[1<<17];
int a[1<<17];
bool f;
int main(){
	n=read();
	pos[0]=1;
	for(int i=2;i<=n;++i){
		printf("XOR 1 %d\n",i);fflush(stdout);
		int x=read();a[i]=x;
		if(f==0&&pos[x]){
			printf("AND %d %d\n",pos[x],i);fflush(stdout);
			int t=read();
			a[1]=t^x;
			f=1;
		}
		else pos[x]=i;
	}
	if(f){
		printf("! %d ",a[1]);
		for(int i=2;i<=n;++i) printf("%d ",a[1]^a[i]);fflush(stdout);
		return 0;
	}
	else{
		printf("AND %d %d\n",1,pos[1]);fflush(stdout);
		int x=read();
		printf("AND %d %d\n",1,pos[n-2]);fflush(stdout);
		x+=read();
		printf("! %d ",x);
		for(int i=2;i<=n;++i) printf("%d ",x^a[i]);fflush(stdout);
	}
}