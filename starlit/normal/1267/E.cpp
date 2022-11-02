#include<bits/stdc++.h>
const int N=103;
using namespace std;
int n,m,a[N][N],sum,ans,now,c[N];
pair<int,int>b[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++)
		scanf("%d",a[i]+j);
	}
	ans=m;
	for(int i=1;i<n;i++){
	    sum=0;
		for(int j=0;j<m;j++)
		b[j]=make_pair(a[j][i]-a[j][n],j),
		sum+=b[j].first;
		sort(b,b+m);
		for(now=0;sum<0&&now<m;now++)
		sum-=b[now].first;
		if(now<=ans){
			ans=now;
			for(int j=0;j<now;j++)
			c[j]=b[j].second;
		}
	}
	printf("%d\n",ans);
	for(int j=0;j<ans;j++)
	printf("%d ",c[j]+1);
}