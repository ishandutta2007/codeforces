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
int n;
int ans[1010];
int main(){
	n=read();
	int pre=-1,fir=-1;
	for(int i=1;i<n;++i){
		printf("? %d %d\n",i,n);
		fflush(stdout);
		int sum=read();
		if(i==1) pre=fir=sum;
		else{
			ans[i-1]=pre-sum,pre=sum;
		}
	}
	printf("? %d %d\n",1,n-1);
	fflush(stdout);int x=read();
	ans[n]=fir-x;
	ans[n-1]=pre-ans[n];
	printf("! ");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");fflush(stdout);
	return 0;
}