#include<bits/stdc++.h>
using namespace std;

int n,m,k,a,v[105],r[105],l[105],b[105];
bool cmp(int x,int y){
	return v[x]>v[y]||v[x]==v[y]&&l[x]<l[y];
}
int main(){
	scanf("%d%d%d%d",&n,&k,&m,&a);
	for(int i=0;i<a;i++){
		int x;scanf("%d",&x);
		v[x]++;l[x]=i;
	}
	for(int i=1;i<=n;i++)b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)r[b[i]]=i;
	if(n==1){return printf("1\n"),0;}
	if(a==m){
		for(int i=1;i<=n;i++)if(r[i]<=k&&v[i])printf("1 ");else printf("3 ");printf("\n");
		return 0;
	}
	if(k==n){
		for(int i=1;i<=n;i++)if(v[i])printf("1 ");else printf("2 ");printf("\n");
		return 0;
	}
	for(int i=1;i<=n;i++)if(r[i]<=k){
		int s=0;
		for(int j=r[i]+1;j<=k+1;j++)s+=v[i]-v[b[j]]+1;
		if(!v[i]||s<=m-a)printf("2 ");else printf("1 ");
	}else if(v[i]+m-a>v[b[k]])printf("2 ");else printf("3 ");
	printf("\n");
	return 0;
}