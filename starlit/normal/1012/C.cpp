#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 5003
#define inf 1e9
using namespace std;
int n,f[N],mn[N],a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),f[i]=inf;
	for(int i=1;i<=(n+1>>1);i++){
		//cerr<<i<<':'<<endl;
		for(int j=n;j;j--){
			if(j>2)f[j]=f[j-2]+max(0,min(a[j-2],a[j-1]+1)-a[j]),
			f[j]=min(f[j],mn[j-3]+max(0,a[j-1]+1-a[j]));
			else f[j]=(i==1?j>1?max(0,a[1]-a[2]+1):0:inf);
			//cerr<<f[j-1]+max(0,min(a[j-2],a[j-1]+1)-a[j])<<'/'<<mn[j-2]+max(0,a[j-1]+1-a[j])<<' ';
			if(j<n)f[j]+=max(0,a[j+1]+1-a[j]);
			//cerr<<f[j]<<' ';
		}
		/*
		for(int j=1;j<=n;j++)
		cerr<<f[j]<<' ';
		cerr<<endl;*/
		mn[0]=inf;
		for(int j=1;j<=n;j++)
		mn[j]=min(mn[j-1],f[j]);
		printf("%d ",mn[n]);
	}
}