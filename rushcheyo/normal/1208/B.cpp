#include <bits/stdc++.h>
using namespace std;

int n,a[2005],b[2005],buc[2005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	int ans=n;
	for(int i=0;;++i){
		for(int j=1;j<=m;++j)buc[j]=0;
		bool flag=true;
		for(int j=1;j<=i;++j)flag&=buc[a[j]]++==0;
		if(!flag)break;
		int j;
		for(j=n+1;j>=i+1;--j){
			ans=min(ans,j-i-1);
			if(j-1==i||buc[a[j-1]]++)break;
		}
	}
	printf("%d\n",ans);
	return 0;
}