#include<bits/stdc++.h>
using namespace std;
int n,m,l[100010],p[100010],nw;
long long sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&l[i]),sum+=l[i];
		if(i+l[i]-1>n)return puts("-1"),0;
	}
	if(sum<n)return puts("-1"),0;
	nw=n-l[m]+1;
	for(int i=m;i>0;--i){
		p[i]=nw;
		if(i>1&&nw-l[i-1]<i-1)nw=i-1;
		else nw-=l[i-1];
	}
	for(int i=1;i<=m;i++){
		printf("%d ",p[i]);
	}
	puts("");
	return 0;
}