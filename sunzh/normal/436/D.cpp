#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int a[100010];
int b[100010];
int f[100010],g[100010];
int L[100010],R[100010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);L[1]=1;
	for(int i=2;i<=n;++i) L[i]=(a[i]==a[i-1]+1?L[i-1]:i);
	R[n]=n;
	for(int i=n-1;i>=1;--i) R[i]=(a[i]==a[i+1]-1?R[i+1]:i);
	int pr=0;
	for(int i=1;i<=n;++i){
		while(pr<m&&b[pr+1]<=a[i]) ++pr;
		g[i]=max(g[i],max(g[i-1],f[i-1])+(b[pr]==a[i]));
		f[i]=max(f[i],f[i-1]+(b[pr]==a[i]));
		for(int j=1;j<=m&&b[j]<a[i];++j) if(a[i]-b[j]+1<=i) {
			g[i]=max(g[i],f[L[i-(a[i]-b[j])]-1]+pr-j+1);
		}
		f[i]=max(f[i],g[i]);
		// printf("f:%d,g:%d\n",f[i],g[i]);
		for(int j=m;j>=1&&b[j]>=a[i];--j)if(b[j]-a[i]+i<=n){
			f[R[i+b[j]-a[i]]]=max(f[R[i+b[j]-a[i]]],g[i]+j-pr);
			// printf("i:%d,j:%d,%d\n",i,j,R[i+b[j]-a[i]]);
		}
	}
	printf("%d\n",f[n]);
}