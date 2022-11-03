#include<bits/stdc++.h>
using namespace std;

int n,m,p,a[1005],b[2005];
int ans=2100000000;
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)scanf("%d",&b[i]);
	sort(a,a+n);sort(b,b+m);
	for(int i=0;i<=m-n;i++){
		int t=0;
		for(int j=0;j<n;j++)t=max(t,abs(a[j]-b[i+j])+abs(p-b[i+j]));
//		printf("%d %d\n",i,t);
		if(t<ans)ans=t;
	}
	printf("%d\n",ans);
	return 0;
}