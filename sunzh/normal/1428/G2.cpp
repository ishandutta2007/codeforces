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
int k;
int F[10];
int cnt;
const int N=999999;
long long f[1000010];
int P10[10]={0,1,10,100,1000,10000,100000,1000000};
int main(){
	k=read();
	for(int i=1;i<=6;++i) F[i]=read();
	memset(f,-0x3f,sizeof(f));f[0]=0;
	for(int p=1;p<=6;++p){
		int s=3*(k-1);
		int t=1;
		while(s){
			t=min(s,t);
//			printf("t:%d\n",t);
			for(int i=N;i>=t*3ll*P10[p];--i) f[i]=max(f[i],f[i-t*3*P10[p]]+1ll*t*F[p]);
			s-=t;
			t<<=1;
		}
	}
	for(int p=6;p>=1;--p){
		for(int l=N;l>=0;--l){
			for(int i=0;i<=l/P10[p]&&i<=9;++i){
				long long v=(i%3?0:1ll*F[p]*(i/3));
				f[l]=max(f[l],f[l-i*P10[p]]+v);
			}
		}
	}
	int q=read();
	while(q--){
		int x=read();
		printf("%lld\n",f[x]);
	}
}