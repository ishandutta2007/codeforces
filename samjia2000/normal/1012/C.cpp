#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 5005;
const int INF = 1.05e9;

int n,a[N];
int f[N][N],g[N][N];
int ans[N];

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	int k=(n+1)/2;
	fo(i,0,n)fo(j,0,k)g[i][j]=f[i][j]=INF;
	fo(i,1,n){
		if (a[i-1]>=a[i])f[i][1]=a[i-1]-a[i]+1;else f[i][1]=0;
	}
	fo(i,1,n){
		fo(j,2,k){
			if (i>2&&f[i-2][j-1]!=INF){
				int tmp=f[i-2][j-1]+a[i-1]-min(a[i-1],min(a[i-2],a[i])-1);
				f[i][j]=min(f[i][j],tmp);
			}
			if (i>3&&g[i-3][j-1]!=INF){
				int tmp=g[i-3][j-1]+a[i-1]-min(a[i-1],a[i]-1);
				f[i][j]=min(f[i][j],tmp);
			}
		}
		fo(j,1,k){
			int tmp=f[i][j]==INF?INF:f[i][j]+a[i+1]-min(a[i+1],a[i]-1);
			g[i][j]=min(g[i-1][j],tmp);
		}
	}
	fo(i,1,k)ans[i]=INF;
	fo(i,1,n)
		fo(j,1,k)
		if (f[i][j]!=INF){
			int tmp=f[i][j]+a[i+1]-min(a[i+1],a[i]-1);
			ans[j]=min(ans[j],tmp);
		}
	fo(i,1,k)printf("%d%c",ans[i],i==k?'\n':' ');
	return 0;
}