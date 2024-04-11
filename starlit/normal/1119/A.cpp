#include<bits/stdc++.h>
const int N=300005;
using namespace std;
int n,a[N],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]^a[1])ans=max(ans,i-1);
	}
	for(int i=1;i<n;i++)
	if(a[i]^a[n])ans=max(ans,n-i);
	printf("%d",ans);
}