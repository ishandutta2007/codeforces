#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200000],b[200000],c[200000],p[233333];

int main(){
	int i,j,k,m,n,ans=0;
	scanf("%d%d",&n,&m);
	if(m==1){
		printf("%d\n",n);
		return 0;
	}
	for(i=1;i<=n;i++)scanf("%d",&c[i]);
	for(i=1;i<n;i++)a[i]=c[i+1]-c[i];
	for(i=1;i<=m;i++)scanf("%d",&c[i]);
	for(i=1;i<m;i++)b[i]=c[i+1]-c[i];
	p[1]=0;
	for(i=2;i<m;i++){
		j=p[i-1];
		while(j && b[j+1]!=b[i])j=p[j];
		if(b[j+1]==b[i])p[i]=j+1;else p[i]=0;
	}
	j=0;
	for(i=1;i<n;i++){
		while(j && a[i]!=b[j+1])j=p[j];
		if(a[i]==b[j+1])j++;
		if(j==m-1){
			ans++;
			j=p[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}