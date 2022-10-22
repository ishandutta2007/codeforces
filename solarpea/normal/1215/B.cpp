#include <bits/stdc++.h>
using namespace std;
int a[200005],n,s[200005],cnt[2];
long long ans[2];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		if(a[i]>0)
		    s[i]=s[i-1];
		else
		    s[i]=s[i-1]+1;
	}
	for(int i=0;i<=n;i++){
		if(s[i]%2)  for(int j=0;j<2;j++)    ans[j]+=cnt[j^1];
		else    for(int j=0;j<2;j++)        ans[j]+=cnt[j];
		cnt[s[i]%2]++;
	}
	printf("%I64d %I64d\n",ans[1],ans[0]);
	return 0;
}