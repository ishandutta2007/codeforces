#include<bits/stdc++.h>
const int N=1003;
using namespace std;
int n,m,a[N],b[N],sum;
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		for(j=0;j<=i;j++)
		b[j]=a[j];
		sort(b,b+i+1);sum=0;
		for(j=i;sum<=m&&j>=0;j-=2)
		sum+=b[j];
		if(sum>m)break;
	}
	printf("%d",i);
}