#include<bits/stdc++.h>
using namespace std;

int getint(){
	int x=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,a[1005][1005],b[1005][1005],c[1005],d[1005],x[1005],y[1005];
bool v[1005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<n-1;){
			j+=b[i][++d[i]]=getint();
			for(int k=0;k<b[i][d[i]];k++)a[i][getint()]=d[i];
		}
	for(int _=1;_<n;_++){
		int i,j;
		for(i=1;i<=n;i++)if(!v[i]&&d[i]==1)break;
		if(i>n)return printf("-1\n"),0;
		for(j=1;j<=n;j++)if(!v[j]&&b[j][a[j][i]]==1)break;
		if(j>n)return printf("-1\n"),0;
		for(int k=1;k<=n;k++)if(!v[k]&&k!=i&&k!=j){
			if(a[k][i]!=a[k][j])return printf("-1\n"),0;
			b[k][a[k][j]]--;
		}
		x[_]=i,y[_]=j;d[j]--;v[i]=1;
	}
	printf("%d\n",n-1);
	for(int i=1;i<n;i++)printf("%d %d\n",x[i],y[i]);
	return 0;
}