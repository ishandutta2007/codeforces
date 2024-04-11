#include<bits/stdc++.h>
using namespace std;
const int N=200000,Q=1050000;
int n,q,x,x1,a[N],p[N][8],t[N],ll[Q],ans[Q],
dp[5100000][8],ss[12];
bool y;
vector<int>no[N];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);x1=x;
		for(int j=2;x>1&&j*j<=x1;j++){
			for(y=0;x%j==0;x/=j,y^=1);
			if(y)p[i][t[i]++]=j;
		}
		if(x>1)p[i][t[i]++]=x;
	}
	for(int i=0;i<q;i++)
	scanf("%d%d",ll+i,&x),no[x].push_back(i);
	for(int i=1;i<=n;i++){
		for(int s=0;s<1<<t[i];s++){
			x=1,x1=0;
			for(int j=0;j<t[i];j++)
			if(s>>j&1)x*=p[i][j];
			else x1++;
			for(int j=0;j<8&&j+x1<12;j++)
			ss[j+x1]=max(ss[j+x1],dp[x][j]);
		}
		for(auto j:no[i])
		for(int k=0;;k++)
		if(ss[k]>=ll[j]){ans[j]=k;break;}
		for(int s=0;s<1<<t[i];s++){
			x=1,x1=0;
			for(int j=0;j<t[i];j++)
			if(s>>j&1)x*=p[i][j];
			else x1++;
			dp[x][x1]=i;
		}
	}
	for(int i=0;i<q;i++)printf("%d\n",ans[i]);
}