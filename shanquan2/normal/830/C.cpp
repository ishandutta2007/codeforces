#include<bits/stdc++.h>
using namespace std;

int n,m,a[105];
long long b[10000005],s,ans;
int main(){
	scanf("%d%I64d",&n,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);s+=a[i];
		for(int j=1;j*j<=a[i];j++)b[m++]=j,b[m++]=(a[i]-1)/j+1;
	}
	b[m++]=1ll<<30;
	sort(b,b+m);m=unique(b,b+m)-b;
//	for(int i=0;i<m;i++)printf("%I64d ",b[i]);printf("\n");
	for(int i=0;i<m;i++){
		long long x=b[i];long long t=0;
		for(int j=0;j<n;j++)t+=(a[j]-1)/x+1;
		long long r=s/t;
		if(x<=r&&ans<r)ans=r;
	}
	printf("%I64d\n",ans);
	return 0;
}